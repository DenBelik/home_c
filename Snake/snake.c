#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"
#include "time.h"
#include "inttypes.h"
#include "string.h"
#include "curses.h"

#define MIN_Y 2

enum {LEFT = 1, UP, RIGHT, DOWN, STOP_GAME = KEY_F(10)};
enum {MAX_TAIL_SIZE = 100, START_TAIL_SIZE = 3, MAX_FOOD_SIZE = 20, FOOD_EXPIRE_SECONDS = 10, SEED_NUMBER = 3};
enum {SNAKE_1 = 1, SNAKE_2 = 2, FOOD = 3};

struct control_buttons {
    int down;
    int up;
    int left;
    int right;
    int key_down;
    int key_up;
    int key_left;
    int key_right;
} control_buttons;

struct control_buttons default_controls = {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT, 's', 'w', 'a', 'd'};

struct food {
    int x;
    int y;
    time_t put_time;
    char point;
    uint8_t enable;
} food[MAX_FOOD_SIZE];

typedef struct snake_t {
    int num;
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
    struct control_buttons controls;
} snake_t;

typedef struct tail_t {
    int x;
    int y;
} tail_t;

int mainMenu(int record) {
    initscr();  // Инициализация curses
    keypad(stdscr, TRUE);  // Включаем поддержку функциональных клавиш
    raw();  // Отключаем буферизацию ввода
    noecho();  // Отключаем отображение вводимых символов
    curs_set(FALSE);  // Скрываем курсор
    printw("------SNAKE-----\n\n");
    printw("Your record: %d\n\n", record);
    printw("Choose game mode\n");
    printw("1. Single player\n");
    printw("2. Versus computer\n");
    printw("3. Exit");
    refresh();
    int key = 0;
    while(1) {
        key = getch();
        switch (key)
        {
        case '1':
            endwin();
            return 1;
        case '2':
            endwin();
            return 2;
        case '3':
            endwin();
            return 0;
            break;
        default:
            break;
        }
    }
}

void initTail(struct tail_t t[], size_t size) {
    struct tail_t init_t = {0, 0};
    for (size_t i = 0; i < size; ++i) {
        t[i] = init_t;
    }
}

void initHead(struct snake_t *head, int x, int y) {
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}

bool checkCollision(struct snake_t *snake) {
        for (int i = 1; i < snake->tsize; ++i) {
            if (snake->x == snake->tail[i].x && snake->y == snake->tail[i].y)
                return TRUE;
        }
    return FALSE;
}

void setColor(int obj){
    attroff(COLOR_PAIR(1));
    attroff(COLOR_PAIR(2));
    attroff(COLOR_PAIR(3));
    switch (obj){
        case 1:{
            attron(COLOR_PAIR(1));
            break;
        }
        case 2:{
            attron(COLOR_PAIR(2));
            break;
        }
        case 3:{
            attron(COLOR_PAIR(3));
            break;
        }
    }
}


void initSnake(snake_t *head[], size_t size, int num, int x, int y, int i) {
    head[i] = (snake_t*)malloc(sizeof(snake_t));
    tail_t *tail = (tail_t*)malloc(MAX_TAIL_SIZE * sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head[i], x, y);
    head[i]->num = num;
    head[i]->tail = tail;
    head[i]->tsize = size + 1;
    head[i]->controls = default_controls;
}

void initFood(struct food f[], size_t size) {
    struct food init = {0, 0, 0, 0, 0};
    for (size_t i = 0; i < size; ++i) {
        f[i] = init;
    }
}

void putFoodSeed(struct food *f) {
    int max_x = 0, max_y = 0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(f->y, f->x, " ");
    f->x = rand() % (max_x - 1);
    f->y = rand() % (max_y - 1) + 1;
    f->put_time = time(NULL);
    f->point = '$';
    f->enable = 1;
    spoint[0] = f->point;
    setColor(FOOD);
    mvprintw(f->y, f->x, "%s", spoint);
}

void repairSeed(struct food f[], size_t nfood, snake_t *head) {
    for(size_t i = 0; i < head->tsize; i++) {
        for(size_t j = 0; j < nfood; j++){
            if(f[j].x == head->tail[i].x && f[j].y == head->tail[i].y && f[i].enable) {
                mvprintw(0, 0, "Repair tail seed %d",j);
                putFoodSeed(&f[j]);
            }
        }
    }
    for(size_t i = 0; i < nfood; i++) {
        for(size_t j = 0; j < nfood; j++){
            if(i!=j && f[i].enable && f[j].enable && f[j].x == f[i].x && f[j].y == f[i].y && f[i].enable) {
                mvprintw(0, 0, "Repair same seed %d",j);
                putFoodSeed(&f[j]);
            }
        }
    }
}

void refreshFood(struct food f[], int nfood) {
    for (size_t i = 0; i < nfood; ++i) {
        if (f[i].put_time) {
            if (!f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS) {
                putFoodSeed(&f[i]);
            }
        }
    }
}

void putFood(struct food f[], size_t number_seeds) {
    for (size_t i = 0; i < number_seeds; ++i) {
        putFoodSeed(&f[i]);
    }
}

bool haveEat(struct snake_t *snake, struct food f[]) {
    for (size_t i = 0; i < MAX_FOOD_SIZE; ++i) {
        if (f[i].enable && snake->x == f[i].x && snake->y == f[i].y) {
            f[i].enable = 0;
            return TRUE;
        }
    }
    return FALSE;
}

void go(struct snake_t *head) {
    setColor(head->num);
    char ch = '@';
    int max_x = 0, max_y = 0;
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(head->y, head->x, " ");
    switch (head->direction) {
        case LEFT:
            if (head->x <= 0)
                head->x = max_x;
            mvprintw(head->y, --(head->x), "%c", ch);
            break;
        case RIGHT:
            if (head->x > max_x)
                head->x = 0;
            mvprintw(head->y, ++(head->x), "%c", ch);
            break;
        case UP:
            if(head->y <= 2)
                head->y = max_y;
            mvprintw(--(head->y), head->x, "%c", ch);
            break;
        case DOWN:
            if (head->y > max_y)
                head->y = 2;
            mvprintw(++(head->y), head->x, "%c", ch);
            break;
        default:
            break;
    }
    refresh();
}

void changeDirection(struct snake_t *snake, const int32_t key) {

    int lower_key = tolower(key);

    if ((lower_key == tolower(snake->controls.down) || lower_key == tolower(snake->controls.key_down)) && snake->direction != UP)
        snake->direction = DOWN;
    else if ((lower_key == tolower(snake->controls.up) || lower_key == tolower(snake->controls.key_up)) && snake->direction != DOWN)
        snake->direction = UP;
    else if ((lower_key == tolower(snake->controls.left) || lower_key == tolower(snake->controls.key_left)) && snake->direction != RIGHT)
        snake->direction = LEFT;
    else if ((lower_key == tolower(snake->controls.right) || lower_key == tolower(snake->controls.key_right)) && snake->direction != LEFT)
        snake->direction = RIGHT;
}

int distance(snake_t snake, const struct food f) {
    return (abs(snake.x - f.x) + abs(snake.y - f.y));
}

void autoChangeDirection(snake_t *snake, struct food f[], int foodSize) {
    int temp = 0;
    for (int i = 1; i < foodSize; i++) {
        if (distance(*snake, f[i]) < distance(*snake, f[temp])) {
            temp = i;
        }
    }
    if ((snake->direction == RIGHT || snake->direction == LEFT) && (snake->y != f[temp].y)) {
        if (f[temp].y > snake->y) {
            snake->direction = DOWN;
        } else {
            snake->direction = UP;
        }
    } else if ((snake->direction == DOWN || snake->direction == UP) && (snake->x != f[temp].x)) {
        if (f[temp].x > snake->x) {
            snake->direction = RIGHT;
        } else {
            snake->direction = LEFT;
        }
    }
}

void goTail(struct snake_t *head) {
    char ch = '*';
    setColor(head->num);
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
    for (size_t i = head->tsize - 1; i > 0; i--) {
        head->tail[i] = head->tail[i - 1];
        if (head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}

void addTail(struct snake_t *head) {
    if (head == NULL || head->tsize > MAX_TAIL_SIZE) 
        return;
    
    head->tsize++;
}

int main(void) {

    int record = 0;
    int score = 0;

    FILE *file = fopen("record.txt", "r");
    if (file) {
        fscanf(file, "%d", &record);
        fclose(file);
    }

    int num_players = mainMenu(record);

    if (num_players == 0) {
        return 0;
    }

    snake_t *snakes[num_players];

    for (int i = 0; i < num_players; ++i) {
        initSnake(snakes, START_TAIL_SIZE, i + 1, (i + 1) * 10, (i + 1) * 10, i);
    }

    initscr();
    keypad(stdscr, TRUE);
    raw();
    noecho();
    curs_set(FALSE);
    mvprintw(0, 0, " Use arrows or wasd for control. Press 'F10' for EXIT");
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    timeout(0);
    initFood(food, MAX_FOOD_SIZE);
    putFood(food, SEED_NUMBER);
    int key_pressed = 0;
    while (key_pressed != STOP_GAME && !(checkCollision(snakes[0]))) {
        key_pressed = getch();
        mvprintw(1, 0, "                                        ");
        attron(COLOR_PAIR(4));
        mvprintw(1, 0, "Score: %d | Record: %d", score, record);
        attroff(COLOR_PAIR(4));
        for (int i = 0; i < num_players; ++i) {
            go(snakes[i]);
            goTail(snakes[i]);
            if (haveEat(snakes[i], food)) {
                if (i == 0)
                    score++;
                addTail(snakes[i]);
            }
        }
        timeout(100);
        refreshFood(food, SEED_NUMBER);
        repairSeed(food, SEED_NUMBER, snakes[0]);
        changeDirection(snakes[0], key_pressed);
        if (num_players > 1) {
            autoChangeDirection(snakes[1], food, SEED_NUMBER);
        }
    }

    if (score > record) {
        file = fopen("record.txt", "w");
        fprintf(file, "%d", score);
        fclose(file);
    }

    for (int i = 0; i < num_players; ++i) {
        free(snakes[i]->tail);
        free(snakes[i]);
    }
    endwin();
    printf("Game over! Your score: %d\n", score);
    printf("Current record: %d\n", record);
    return 0;
}
