//LinkedBag.java

public class LinkedBag<T> implements BagInterface<T>

{

    private class Node

    {

        T entry;

        Node next;

        Node(T entryPortion)

        {

            this(entryPortion, null);

        }

        Node(T entryPortion, Node nextNode)

        {

            entry = entryPortion;

            next = nextNode;

        }

    }

    private Node first; // beginning of bag

    private int n; // number of elements in bag

    private int maxsize=10; //max size of the bag

    public LinkedBag() {

        this.first = null;

        this.n = 0;

    }

    public int getCurrentSize()

    {

        return this.n;

    }

    public boolean isFull()

    {

        return this.n==this.maxsize;

    }

    public boolean isEmpty()

    {

        return this.n==0;

    }

    public boolean add(T item) {

        if(!isFull())

        {

            Node oldfirst = this.first;

            this.first = new Node(item,oldfirst);

            this.n++;

            return true;

        }

        else

            return false;

    }

    public T remove()

    {

        Node oldfirst = this.first;

        this.first=oldfirst.next;

        this.n--;

        T rem=oldfirst.entry;

        return rem;

    }

    public boolean contains(T anEntry)

    {

        Node tmp=this.first;

        for(int i=0;i<n;i++)

        {

            if(tmp.entry==anEntry)

                return true;

            tmp=tmp.next;

        }

        return false;

    }

    public boolean remove(T anEntry)

    {

        Node tmp=this.first;

        for(int i=0;i<n;i++)

        {

            if(tmp.entry==anEntry)

            {

                this.n--;

                tmp=tmp.next;

                return true;

            }

            tmp=tmp.next;

        }

        return false;

    }

    public void clear()

    {

        this.n=0;

        this.first=null;

    }

    public int getFrequencyOf(T anEntry)

    {

        Node tmp=this.first;int ct=0;

        for(int i=0;i<n;i++)

        {

            if(tmp.entry==anEntry)

                ct++;

            tmp=tmp.next;

        }

        return ct;

    }

    public T[] toArray()

    {

        T arr[]=(T[])java.lang.reflect.Array.newInstance(Integer.class,n);

        Node tmp=this.first;

        for(int i=0;i<n;i++)

        {

            arr[i]=tmp.entry;

            tmp=tmp.next;

        }

        return arr;

    }

}

/**

 * LinkedBagDemo - test case of the class

 */

class LinkedBagDemo

{

    public static void main(String[] args) {

        LinkedBag<Integer> l=new LinkedBag<Integer>();

        for(int i=0;i<3;i++)

        {

            System.out.println("adding "+i+" to bag");

            l.add(i);

        }

        for(int i=0;i<10;i++)

            if(l.contains(i))

            { System.out.println("frequency of "+i+" is "+l.getFrequencyOf(i));

                System.out.println("removing: "+l.remove(i));

            }

        System.out.println("bag size is "+l.getCurrentSize());

        if(l.isEmpty())

            System.out.println("bag is empty");

        else

            System.out.println("bag is not empty");

    }

}