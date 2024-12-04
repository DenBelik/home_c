  #include <stdio.h>

  void sort_even_odd(int n, int a[]) {
    int temp[n];
    int j = 0;
    int k = n - 1;

    for (int i = 0; i < n; ++i) {
      if (a[i] % 2 == 0) {
        temp[j++] = a[i];
      }
    }

    for (int i = 0; i < n; ++i) {
      if (a[i] % 2 != 0) {
        temp[j++] = a[i];
      }
    }

    for (int i = 0; i < n; ++i) {
      a[i] = temp[i];
    }
  }

  int is_digit(char c) {
    return ((c >= '0') && (c <= '9'));
  }

int input_get(int arr[])
{
int i = 0;
char c;
    while((c=getchar())!='\n')
    {
        if(is_digit(c))
        {
            int number=0;
            do
            {
                number=number*10+c-'0';
                c=getchar();
            }
            while(is_digit(c));
            arr[i++] = number;
            if(c=='\n')
                break;
        }
    }
    return i;
}


  int main(void) {
    enum {BUFFER_SIZE = 100};
    int buffer[BUFFER_SIZE];
    int size = input_get(buffer);
    sort_even_odd(size, buffer);

    for (int i = 0; i < size; i++) {
        printf("%d ", buffer[i]);
    }

    return 0;
  }  