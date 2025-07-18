import java.util.Scanner;

class node {
    public int data;
    public node next;
}

class singly {
    public node first;
    public int iCount;

    public singly() {
        first = null;
        iCount = 0;
    }

    public void display() {
        if (first == null) {
            System.out.println("linked list is empty");
        }
        node temp = first;
        while (temp != null) {
            System.out.print("|" + temp.data + "|->");
            temp = temp.next;
        }
    }

    public void insertFirst(int no) {
        node newn = new node();
        newn.data = no;
        newn.next = null;
        if (first == null) {
            first = newn;
        } else {
            newn.next = first;
            first = newn;
        }
        iCount++;
    }

    public void insertLast(int no) {
        node newn = new node();
        newn.data = no;
        newn.next = null;
        if (first == null) {
            first = newn;
        } else {
            node temp = first;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newn;
            newn.next = null;
        }
        iCount++;
    }

    public void insertAtpos(int no, int pos) {
        if (pos < 1 || pos > iCount + 1) {
            System.out.println("invalid position");
            return;
        }
        if (pos == 1) {
            insertFirst(no);
        } else if (pos == iCount + 1) {
            insertLast(no);
        } else {
            node newn = new node();
            newn.data = no;
            newn.next = null;
            node temp = first;
            for (int iCnt = 1; iCnt <= pos - 2; iCnt++) {
                temp = temp.next;
            }
            newn.next = temp.next;
            temp.next = newn;
            iCount++;
        }
    }

    public void deleteFirst() {
        if (first == null) {
            System.out.println("linked list is empty");
            return;
        } else if (first.next == null) {
            first = null;
        } else {
            first = first.next;
        }
        iCount--;
    }

    public void deleteLast() {
        if (first == null) {
            System.out.println("linked list is empty");
            return;
        } else if (first.next == null) {
            first = null;
        } else {
            node temp = first;
            while (temp.next.next != null) {
                temp = temp.next;
            }
            temp.next = null;
        }
        iCount--;
    }

    public void deleteAtpos(int pos) {
        if (pos < 1 || pos > iCount) {
            System.out.println("invalid position");
            return;
        }
        if (pos == 1) {
            deleteFirst();
        } else if (pos == iCount) {
            deleteLast();
        } else {
            node temp = first;
            for (int iCnt = 1; iCnt <= pos - 2; iCnt++) {
                temp = temp.next;
            }
            node target = temp.next;
            temp.next = target.next;
            iCount--;
        }
    }

    public int count() {
        return iCount;
    }
}

class singlyLL {
    public static void main(String args[]) {
        singly sobj = new singly();
        int iRet = 0;
        int iNo = 0;
        int iPos = 0;
        int ch = 0;
        Scanner s = new Scanner(System.in);
        do {
            System.out.println("------------MENU------------------");
            System.out.println("1.INSERT AT FIRST POSITION");
            System.out.println("2.INSERT AT LAST POSITON");
            System.out.println("3.INSERT AT ANY POSITION");
            System.out.println("4.DELETE AT FIRST POSITION");
            System.out.println("5.DELETE AT LAST POSITON");
            System.out.println("6.DELETE AT ANY POSITION");
            System.out.println("7.DISPLAY ");
            System.out.println("8.COUNT");
            System.out.println("9.EXIT");
            System.out.println("PLEASE ENTER YOUR CHOICE ");
            ch = s.nextInt();
            if (ch < 1 || ch > 9) {
                System.out.println("invalid input");
            }
            System.out.println();
            switch (ch) {

                case 1:
                    System.out.println("Enter Number you want to insert:");
                    iNo = s.nextInt();
                    sobj.insertFirst(iNo);
                    break;
                case 2:
                    System.out.println("Enter Number you want to insert:");
                    iNo = s.nextInt();
                    sobj.insertLast(iNo);
                    break;
                case 3:
                    System.out.println("Enter Number you want to insert:");
                    iNo = s.nextInt();
                    System.out.println("Enter position");
                    iPos = s.nextInt();
                    sobj.insertAtpos(iNo, iPos);
                    break;
                case 4:
                    sobj.deleteFirst();
                    break;
                case 5:
                    sobj.deleteLast();
                    break;
                case 6:
                    System.out.println("Enter position");
                    iPos = s.nextInt();
                    sobj.deleteAtpos(iPos);
                    break;
                case 7:
                    sobj.display();
                    System.out.println();
                    break;
                case 8:
                    iRet = sobj.count();
                    System.out.println("NUMBER OF ELEMENTS IN LINKED LIST :" + iRet);
                    break;
                case 9:
                    System.out.println("Existing program");
            }
        } while (ch != 9);

    }
}
