void swap(struct ListNode** a, struct ListNode** b, struct ListNode** head,struct ListNode** old){
   
    if(*b==NULL)
        return;
    struct ListNode*temp=NULL;
    if(*a==*head)
        *head=*b;
    else
        (*old)->next=(*a)->next;
    temp=(*b)->next;
    (*b)->next=*a;
    (*a)->next=temp;
    *old=*a;
}
struct ListNode* swapPairs(struct ListNode* head){
    
    if(head==NULL || head->next==NULL)
        return head;
        
    struct ListNode*ptr=head,*temp=NULL,*old=NULL;
    while(ptr!=NULL){
        swap(&ptr,&(ptr->next),&head,&old);
        ptr=ptr->next;
    }
    return head;
}
