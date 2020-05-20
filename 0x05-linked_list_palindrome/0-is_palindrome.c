#include "lists.h"

unsigned int get_length(listint_t *head) 
{
    unsigned int len = 0;
    listint_t* temp = head;

    while (temp) {
        len++;
        temp = temp->next;
    }
    return len;
}

void set_j(listint_t *head, listint_t **j, unsigned int len)
{
    int curr = 0;
    listint_t *jprev = NULL;
    listint_t *temp = NULL;

    *j = head;
    while (*j)
    {
        temp = *j;
        *j = (*j)->next;
        if ((unsigned int)curr >= (len + 1) / 2) {
            //reverse the connection
            temp->next = jprev;
        }
        jprev = temp;
        curr++;
    }
    *j = jprev;
}

/**
 * is_palindrome - function description
 * @head: parameter description
 * Return: return description
 */
int is_palindrome(listint_t **head)
{
    unsigned int len = 0;
    listint_t *i = NULL;
    listint_t *j = NULL;
    listint_t *temp = NULL;
    listint_t *jprev = NULL;
    int pal = 1;

    if (!head)
        return 0;

    len = get_length(*head);
    if (len == 0 || len == 1)
        return 1;
    i = *head;
    set_j(*head, &j, len);

    //loop backwards, swapping back the pointer at every step until i and j pass
    while (i != j && !(j->next == i && (i->next != j))) //if palindrome is even, need to check final center value after while loop
    {
        if (i->n != j->n)
            pal = 0;

        i = i->next;

        temp = j;
        j = j->next;

        temp->next = jprev;
        jprev = temp;
    }
    return pal;
}
