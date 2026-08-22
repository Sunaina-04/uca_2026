#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkBalance(char *input) {
	int length = strlen(input);

	char *stack = (char*) malloc(length * sizeof(char));
	if (stack == NULL) {
		printf("Memory allocation failed for stack");
		return 0;	
	}

	int top = -1; //  stack pointer 
	
	for (int i = 0; i < length; i++) {
		char ch = input[i];

		if (ch == '(' || ch == '[' ||ch == '{') {
			stack[++top] = ch;	
		}

		else if (ch == ')' || ch == ']' ||ch == '}') {
			if (top == -1) {
				free(stack);
				return 0;
			}

			char lastOpen = stack[top];

			if ((ch == ')' && lastOpen == '(') || 
					(ch == '}' && lastOpen == '{') ||
					(ch == ']' && lastOpen == '[') ) {
				top --;
			}else {
				free(stack);
				return 0;
			}
		}
	}
	int result = (top == -1);
	free(stack);
	return result;
}

int main() {
	char *buffer = NULL;
	//viva abt size_t
	size_t buffersize = 0;

	printf("Enter input string: ");
	ssize_t character_read = getline(&buffer, &buffersize, stdin);
	
	if (character_read == -1) {
		printf("Error reading input");
		free(buffer);
		return -1;
	}
	// clean the input
	buffer[strcspn(buffer, "\n")] = '\0';
	
	if (checkBalance(buffer) == 1) {
		printf("The string is balanced.\n");
	} else {
		printf("The string is not balanced.\n");
	}

	free(buffer);
	return 0;
}
