#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	int* array;
	int top;
	int size;
}Stack;


// The return type Stack* indicates that the function returns a pointer to a Stack struct rather than a copy of the struct itself.
Stack* createStack(int capacity) {
	Stack *stack = (Stack*) malloc (sizeof(Stack));
	stack->size = capacity;
	stack->top = -1;
	stack->array = (int*) malloc (capacity * sizeof(int));
	return stack;
}

void push (Stack *stack, int value) {
	stack->array[++stack->top] = value;
}

int pop(Stack *stack) {
	return stack->array[stack->top--];
}

int isEmpty(Stack *stack) {
	stack->top == -1;
}

int isFull(Stack *stack) {
	stack-> top == stack->size;
}

void freeStack (Stack *stack) {
	free(stack->array);
	free(stack);
}
int postfixExp(char *input){
	int length = strlen(input);
	// create an array stack 
	Stack *stack = createStack(length);

	int i = 0;
	while (input[i] != '\0') {
		char ch = input[i];

		if (isspace((unsigned char) ch)) {
			i++;
			continue;
		}
	
		if (isdigit((unsigned int)ch)) {
			int num = 0;
			while (isdigit((unsigned int)input[i])) {
				num = num * 10 + (input[i] - '0');
				i++;
			}
			push(stack, num);
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){
			char op = ch;
			if (stack-> top >=1) {
				int num2 = pop(stack);
                                int num1 = pop(stack);
				if (op == '+') {
					push(stack, num1 + num2);
				}
				else if (op == '-') {
                                        push(stack, num1 - num2);
                                }
				else if (op == '*') {
                                        push(stack, num1 * num2);
                                }
				else if (op == '/') {
                                        push(stack, num1 / num2);
				}
			}else {
				printf("Not enough numbers\n");
				freeStack(stack);
				exit(1);
			}
		}
		i++;
	}

	int result = pop(stack);
	freeStack(stack);
	return result;
}

int main() {
	// tells getlilne that we dont have an existing memory allocation so it should handle allocating initial memory block for us on heap using malloc()
	char *buffer = NULL;
	// variable to keep track of how many bytes of memory it allocated 
	size_t buffersize = 0;

	printf("Enter string: ");
	// reads entire line typed by user until they hit enter.
	// Automatically expands memory as user types 
	// returns total number of characters read  
	ssize_t characters_read = getline(&buffer, &buffersize, stdin);

	if (characters_read == -1) {
		printf("error reading input");
		free (buffer);
		return -1;
	}

	// finds "\n" in string and returns its index which is replaced by end char. if not found, returns leangth of the string, once again which is correct index for adding end char.
	buffer[strcspn(buffer, "\n")] = '\0';
	
	printf("%d\n", postfixExp(buffer));
	free(buffer);
	return 0;
}
