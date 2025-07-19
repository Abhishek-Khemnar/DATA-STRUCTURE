import java.util.Scanner;

class node {
    int data;
    node next;
}

class Queuex {
    public node first;
    public int icount;

    public Queuex() {
        first = null;
        icount = 0;
    }

    public void Enqueue(int no) {
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
        }
        icount++;
    }

    public int Dequeue() {
        if (first == null) {
            System.out.println("queue is empty");
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
            System.out.println("queue is empty");
            return;
        }
        node temp = first;
        while (temp != null) {
            System.out.print("|" + temp.data + "| -");
            temp = temp.next;
        }

    }

    public int Count() {
        return icount;
    }
}

class Queue {
    public static void main(String arg[]) {
        Queuex sobj = new Queuex();
        int iRet = 0;
        int iNo = 0;
        int iCnt = 0;
        int ch = 0;
        Scanner s = new Scanner(System.in);
        do {

            System.out.println("------------MENU------------------");
            System.out.println("1.ENQUEUE NUMBER");
            System.out.println("2.DEQUEUE NUMBER");
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
                    System.out.println("Enter Number you want to Enqueue:");
                    iNo = s.nextInt();
                    sobj.Enqueue(iNo);
                    break;
                case 2:
                    iRet = sobj.Dequeue();
                    if (iRet > 0 || sobj.Count() > 0) {
                        System.out.println("Dequeue elemnts is :" + iRet);
                    }
                    break;
                case 3:
                    iCnt = sobj.Count();
                    System.out.println("Number of elements in queue :" + iCnt);
                    break;
                case 4:
                    sobj.Display();
                    System.out.println();
                    break;
                case 5:
                    System.out.println("Existing program");

            }

        } while (ch != 5);
    }
}
