package ass1.setA;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

public class linkedList {
    public static void main(String[] args) {
        LinkedList<String> linkedList=new LinkedList<>();
        linkedList.add("red");
        linkedList.add("blue");
        linkedList.add("yellow");
        linkedList.add("orange");

       // Iterator<String> iterator=linkedList.iterator();
        ListIterator<String>  iterator= linkedList.listIterator();

        System.out.println("linked list:");
        while(iterator.hasNext()){
            System.out.print(iterator.next()+" ");
        }

        System.out.println();
        ListIterator<String> lastIterator=linkedList.listIterator(linkedList.size());

        System.out.println("From last:");
        while (lastIterator.hasPrevious()){
            System.out.print(lastIterator.previous()+" ");
        }
        //---------creating new list--------
        List<String> list=new LinkedList<>();
        list.add("pink");
        list.add("green");

        linkedList.addAll(list);

        System.out.println();
        System.out.println("new linked list:");
        System.out.println(linkedList);

    }
}
