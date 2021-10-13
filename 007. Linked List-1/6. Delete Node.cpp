//Node *deleteNodeRec(Node *head, int pos) {
//	//Write your code here
//    if(head == NULL){
//        return head;
//    }
//    if(pos == 0){
//        Node *temp=head;
//        head= head->next;
//        delete temp;
//        return head;
//    }
//    if(pos == 1){
//        Node *temp= head->next;
//        if(temp == NULL){
//            return head;
//        }
//        Node *temp2= temp->next;
//        head->next= temp2;
//        delete temp;
//        return head;
//    }
//    head->next= deleteNodeRec(head->next,pos-1);
//    return head;
//}
/** Alternate Method **/

Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    if(head == NULL || pos<0){
        return head;
    }

    if(pos == 0){
        Node *temp= head;
        head= head->next;
        delete temp;
        return head;
    }else{
        head->next= deleteNodeRec(head->next,pos-1);
        return head;
    }
}
