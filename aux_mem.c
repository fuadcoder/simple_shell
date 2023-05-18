#include "shell.h"

/**
 * _memcpy - this copies info in between void pointers
 * @newptr: this is the destination pointer
 * @ptr: this is the source pointer
 * @size: this is the size of a  new pointer
 * Return: no return
 */

void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int index;

	for (index = 0; index < size; index++)
		char_newptr[index] = char_ptr[index];
}

/**
 * _realloc - this will reallocate a memory block
 * @ptr: the pointer to a memory allocated before
 * @old_size: the size, in bytes, of a space of ptr allocated
 * @new_size: the new size, in bytes, of the new memory block
 *
 * Return: ptr
 * if new_size == old_size,then return ptr without any changes
 * if the malloc fails, return NULL
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}

/**
 * _reallocdp - this reallocates the memory block of a double pointer
 * @ptr: the double pointer to the memory allocated before
 * @old_size: the size, in bytes, of the space of ptr allocated
 * @new_size: the new size, in bytes, of a new memory block
 *
 * Return: ptr
 * if new_size == old_size, returns ptr without changes
 * if the malloc fails, return NULL
 */

char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int index;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (index = 0; index < old_size; index++)
		newptr[index] = ptr[index];

	free(ptr);

	return (newptr);
}
