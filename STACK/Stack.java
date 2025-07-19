import java.util.Scanner;

class node {
    int data;
    node next;
}

class Stackx {
    public node first;
    public int icount;

    public Stackx() {
        first = null;
        icount = 0;
    }

    public void Push(int no) {
        node newn = new node();
        newn.data = no;
        newn.next = null;
        if (first == null) {
            first = newn;
        } else {
            newn.next = first;
            first = newn;
        }
        icount++;
    }

    public int Pop() // deletefirst
    {
        if (first == null) {
            System.out.println("stack is empty");
            return 0;
        } else {
            int ivalue = first.data;
            first = first.next;
            icount--;
            return ivalue;
        }
    }

    public void Display() {
        if (first == null) {
            System.out.println("stack is empty");
            return;
        }
        node temp = first;
        while (temp != null) {
            System.out.println("|" + temp.data + "|");
            temp = temp.next;
        }

    }

    public int Count() {
        return icount;
    }
}

class stack {
    public static void main(String arg[]) {
        Stackx sobj = new Stackx();
        int iRet = 0;
        int iNo = 0;
        int iCnt = 0;
        int ch = 0;
        Scanner s = new Scanner(System.in);
        do {
            System.out.println("------------MENU------------------");
            System.out.println("1.PUSH NUMBER");
            System.out.println("2.POP NUMBER");
            System.out.println("3.COUNT");
            System.out.println("4.DISPLAY");
            System.out.println("5.EXIT");
            System.out.println("PLEASE ENTER YOUR CHOICE ");
            ch = s.nextInt();
            if (ch < 1 || ch > 5) {
                System.out.println("invalid input");
            }
            System.out.println();
            switch (ch) {

                case 1:
                    System.out.println("Enter Number you want to PUSH:");
                    iNo = s.nextInt();
                    sobj.Push(iNo);
                    break;
                case 2:
                    iRet = sobj.Pop();
                    if (iRet > 0 || sobj.Count() > 0) {
                        System.out.println("poped elemnts is :" + iRet);
                    }
                    break;
                case 3:
                    iCnt = sobj.Count();
                    System.out.println("Number of elements in stack :" + iCnt);
                    break;
                case 4:
                    sobj.Display();
                    break;
                case 5:
                    System.out.println("Existing program");

            }

        } while (ch != 5);
    }
}
