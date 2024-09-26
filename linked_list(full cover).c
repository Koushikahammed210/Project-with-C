//In this code I will try to cover all the necessary codes in linked list for our mid
/*there are many topics to be covered
1.singly
2.doubly
3.Nested linked list
We will start with very basic code how to implant a node toward the most advanced topics
thing we will learn
1. How to build a node
2. how a connect another node with previous node
3.how to go reverse from last node to first node
4. Now we can build singly
5. we will learn doubly
6. we will create doubly
7. we will learn to code the function to print linked list forward
8. we will learn to code the function to print linked list backward
9. we will learn how to insert a node in the beginning and then in the middle then in the ending
10. we will learn how to delete a node from the list
11. we will learn how to free the deleted node to avoid memory leaks
12. we will learn how to code a nested linked list

before starting I want you to learn the importance of leveling each data type and addresses and mostly why we
should level the whole node;
leveling the whole node is very necessary because it makes a roadmap how your nodes would be connected
to each other how should they act.
for example , in a node I have data type of int a ,which storing 5 and his tail is going to hold the address of next node
now I am naming this node as "head". Now I have two options to do either set a node with 6 or node with 7 with it, But
how to understand the whole node? as node doesn't only contain data but also am address, if I name them second and
third and create a space in memory for them it is easy to add them with head, your brain will not burnout asking where to
connect. So without farther delay lets' start coding*/

//simple code to build a node head who will have a data type int a and an address, malloc would do the job to create
//space in memory for head

#include<stdio.h>
#include<stdlib.h>

struct Node{
         int data;
         struct Node* next;
         //this next will contain the value of the node which is coming next
};

int main(){
         struct Node* head= NULL;
         //this is naming of head leveled node who has no space in memory
         head=(struct Node*)malloc(sizeof(struct Node));
         //now malloc is going to create a space in memory for head accordingly the 'head' needed
         head->data=5;
         head->next=NULL;
         //as this is a single node so there is no node address to initialize in heads' next ,so it ends here
         return 0;
}

// here a simple code is created with one single node
//Lets' create a new node and add to head
#include<stdio.h>
#include<stdlib.h>

struct Node{
         int data;
         struct Node* next;

};

int main(){
         struct Node* head= NULL;
         struct Node* second=NULL;
         //another node we are naming second here head and second don't have any existence in memory
         head=(struct Node*)malloc(sizeof(struct Node));
         second=(struct Node*)malloc(sizeof(struct Node));
         //now malloc is going to create a space in memory for head and second accordingly the 'head' and second needed
         head->data=5;
         head->next=second;
         //here we go now the address of second is implanted into head
         second->data=6;
         second->next=NULL;

         return 0;
}
//did you see that ? How we added new node to previous node? observe again
// we can connect as much as nodes we want

/* Now how about connecting the nodes backward?
I know you have already figured it out that if we follow the implantation process backward we can do it like connecting
third to second ,second to head and head to NULL;
Let do it then*/

 #include<stdio.h>
#include<stdlib.h>

struct Node{
         int data;
         struct Node* next;
         struct Node* prev;
         //just for satisfaction we created a data type of struct named "prev" to hold the previous address

};

int main(){
         struct Node* head= NULL;
         struct Node* second=NULL;
         struct Node* third=NULL;

         head=(struct Node*)malloc(sizeof(struct Node));
         second=(struct Node*)malloc(sizeof(struct Node));
         third=(struct Node*)malloc(sizeof(struct Node));

         head->data=5;
         //head->next=second;
         head->prev=NULL;

         second->data=6;
         //second->next=third;
         second->prev=head;

         third->data=7;
         //third->next=NULL;
         third->prev=second;

         return 0;
}

//we have successfully covered singly; I hope you know singly goes one way but what we want to go forward and backward?
// there comes the concept doubly; a two way linked ,linked list which allows us to travel forward and backward;

// you guys may have been worring how to build this doubly honestly it is too easy that we have already coded doubly ;
// let me remove some comment from the previous code

#include<stdio.h>
#include<stdlib.h>

struct Node{
         int data;
         struct Node* next;
         struct Node* prev;
         //just for satisfaction we created a data type of struct named "prev" to hold the previous address

};

int main(){
         struct Node* head= NULL;
         struct Node* second=NULL;
         struct Node* third=NULL;

         head=(struct Node*)malloc(sizeof(struct Node));
         second=(struct Node*)malloc(sizeof(struct Node));
         third=(struct Node*)malloc(sizeof(struct Node));

         head->data=5;
         head->next=second;
         head->prev=NULL;

         second->data=6;
         second->next=third;
         second->prev=head;

         third->data=7;
         third->next=NULL;
         third->prev=second;

         return 0;
}

//there you go doubly is created. See it was too easy.

/* Now I am going to introduce you with two functions basically their job is to print this list
one function would be for printing list but the next one is tricky because it has a hard job to print list backward
you can think inside your mind which logic is going to print list forward and backward? In this mean time I am coding the function
*/

void printList(struct Node* node){
         while(node!=NULL){
                  printf("%d->",node->data);
                  node=node->next;
         }
         printf("NULL\n");
}

/*here printList function is not going to return anything so we are using ' void '
we are turning Node structure into node and rest of the work would be done under 'node'
each node has two things [ || data || address|| ]
until we find NULL address we are going to print the data part only not the address part
 if we call this function in main function we are going to get something like this 5->6->7->NULL*/

 //Function creation for printing Backward
 // Have you got the logic?
 //Lets' match your logic with mine
void printBackward(struct Node* back) {
    while (back != NULL) {
        printf("%d->", back->data);
        back = back->prev;  // Move to the previous node
    }
    printf("NULL\n");  // End of the list
}

//I hope you have learnt the Functions now how to call them in main function to make them work?

/*Listen we have to start from head if we are printing the list forward and we need to start from third(the last node) if we
want to print backward*/

//function call to print forward
printList(head);
//function call to print backward
printBackward(third);

// Now lets build the whole code and run on compiler to check if everything is working perfectly
#include<stdio.h>
#include<stdlib.h>

struct Node{
         int data;
         struct Node* next;
         struct Node* prev;
         //just for satisfaction we created a data type of struct named "prev" to hold the previous address

};
void printList(struct Node* node){
         while(node!=NULL){
                  printf("%d->",node->data);
                  node=node->next;
         }
         printf("NULL\n");
}

void printBackward(struct Node* back) {
    while (back != NULL) {
        printf("%d->", back->data);
        back = back->prev;  // Move to the previous node
    }
    printf("NULL\n");  // End of the list
}

int main(){
         struct Node* head= NULL;
         struct Node* second=NULL;
         struct Node* third=NULL;

         head=(struct Node*)malloc(sizeof(struct Node));
         second=(struct Node*)malloc(sizeof(struct Node));
         third=(struct Node*)malloc(sizeof(struct Node));

         head->data=5;
         head->next=second;
         head->prev=NULL;

         second->data=6;
         second->next=third;
         second->prev=head;

         third->data=7;
         third->next=NULL;
         third->prev=second;

         //function call to print forward
          printList(head);
         //function call to print backward
          printBackward(third);


         return 0;
}

//Now our task is to insert a node at any position we are not going with any function here because DIU is not that rough
/* think about the logic to insert a node at any position in singly or doubly, if you have learned the previous parts carefully
I can assure you have already made a plan how to implant a node in any position.

If we are dealing with singly and we have to insert a node at beginning or at middle or at the end
to insert in the beginning we just have to insert the address of head in the new nodes tail. Imagine the node is "New-node"
and we just have to push data and address (of head) here
New_node->data=10;
New_node->next=head;

DONE!

what if we have to insert in any middle position?
like between second and third?
we just need to add the address of New_node to second and address of third node to New_node

Done!

what about at the end?

we know here third node is at the end but we have to locate New_node to the end,
just give the third node ,the address of New_node and in New_node give it the next address to NULL;

I am doing the inserting in the middle here I am giving you the task to complete rest like inserting in the beginning and end

*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
         int data;
         struct Node* next;
         //struct Node* prev;
         //just for satisfaction we created a data type of struct named "prev" to hold the previous address

};
void printList(struct Node* node){
         while(node!=NULL){
                  printf("%d->",node->data);
                  node=node->next;
         }
         printf("NULL\n");
}

/*void printBackward(struct Node* back) {
    while (back != NULL) {
        printf("%d->", back->data);
        back = back->prev;  // Move to the previous node
    }
    printf("NULL\n");  // End of the list
}
*/
int main(){
         struct Node* head= NULL;
         struct Node* second=NULL;
         struct Node* third=NULL;
         struct Node* New_node=NULL;

         head=(struct Node*)malloc(sizeof(struct Node));
         second=(struct Node*)malloc(sizeof(struct Node));
         third=(struct Node*)malloc(sizeof(struct Node));
         New_node=(struct Node*)malloc(sizeof(struct Node));

         head->data=5;
         head->next=second;
         //head->prev=NULL;

         second->data=6;
         second->next=New_node;
         //second->next=third;
         //second->prev=head;

         New_node->data=10;
         New_node->next=third;

         third->data=7;
         third->next=NULL;
         //third->prev=second;


         //function call to print forward
          printList(head);
         //function call to print backward
          //printBackward(third);


         return 0;
}

//I Hope you have done your task inserting New_node at the beginning and at the end
//Now Want you to give you a hard task to sharp your coding mind
/* Think of a doubly linked list which will contain a int, a float ,a char type value , there is a p who will direct this list forward
and q who will direct this list backward you have to build three nodes and connect them properly. after you have done that
code three different codes one to insert New_node in the beginning, another to insert in the middle and last one to insert
in the end; NB; Logic and structure drawing is the key to understand this type code and it makes the coding easier
*/

//Now deleting a Node

/* honestly it is so easy that you have already made a plan to delete any node from the list
if we have to delete the last node we just have to make change in the code before that one
         consider we want to delete third node so we will change the address in second node , we will set it
         to NULL so automatically third node is no more connected to the list.*/
//just like this
         head->data=5;
         head->next=second;


         second->data=6;
         second->next=NULL;


         third->data=7;
         third->next=NULL;

//And DONE! The last node is deleted

// how to delete a node in the middle?
// simple just connect the nodes standing at two side of that node automatically the middle code will fall down
         head->data=5;
         head->next=third;


         second->data=6;
         second->next=NULL;


         third->data=7;
         third->next=NULL;

 //The second has no connection with anyone

 //what if we try to delete the head?

 //No issue just memorize this code

  struct Node* temp = head;  // Temporarily hold the head node for freeing
    head = head->next;  // Move head to the next node
    free(temp);
//Now we should know why free() is necessary ? using free() helps to bypass the risk of memory leak
// Whenever you delete any node please try to free the node. It is a good practice.
syntax:
free("level of the node");

// I am glad that we are at the ending. We have one tiny complex topic left "Nested Linked List"
/* Nested Linked LIst is a linked list where one node stays inside a another node
how this is gonna work actually?
imagine I want to put a nested linked list in second node (singly linked list)
so how we are going to do that?
we have to create two address holders in second node so that it can hold the
address to go to the next node and also can go to the nested one
So heres comes the main discussion: what are the things we need to structure this linked list
1.first of all we need a structure for nested linked list
2. we need to modify the previous node that makes the each main node able to hold nested Node
3. we need to take memory from pc to create nested loops
4. and we are done.*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
         int data;
         struct Node* next;
         struct Node* nested;

};

struct Nested{
         int data;
         struct Nested* nested_next;
};

int main(){
         struct Node* head= NULL;
         struct Node* second=NULL;
         struct Node* third=NULL;


         head=(struct Node*)malloc(sizeof(struct Node));
         second=(struct Node*)malloc(sizeof(struct Node));
         third=(struct Node*)malloc(sizeof(struct Node));


         head->data=5;
         head->next=second;
         head->nested = NULL;

         second->data=6;
         second->next=third;

         third->data=7;
         third->next=NULL;
         third->nested = NULL;

         struct Nested* first=NULL;
         first=(struct Nested*)malloc(sizeof(struct Nested));
         second->nested=first;
         first->data=12;
         first->nested_next=NULL;


         return 0;
}

// here you go I hope you all have learned this much to understand all the ** marked placed why
//we are dealing with that kind of code please do a task I gave to you and insert a function to check if your code is working properly
/*TASK:
1. insert linked list as nested in each and every main node
2. print the node to find out if your job is done perfectly?

I have given the function below copy paste it to your code and call it in main function by the name of
(head) */

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Node data: %d\n", temp->data);

        // Check if there is a nested linked list
        if (temp->nested != NULL) {
            printf("  Nested List: ");
            struct Nested* nestedTemp = temp->nested;
            while (nestedTemp != NULL) {
                printf("%d -> ", nestedTemp->data);
                nestedTemp = nestedTemp->nested_next;
            }
            printf("NULL\n");
        }

        temp = temp->next;  // Move to the next node in the outer list
    }
}

/* Please guyz for any kind of issue inbox me to get your doubt clear and I strongly suggested you to
solve previous year question for best performance...

#include<stdio.h>
int main(){

printf("Best Of Luck");

return 0;
};*/
