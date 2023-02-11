package ass1.setA;

import javax.security.sasl.SaslClient;
import java.util.Scanner;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

public class collectionSort {
    public static void main(String[] args) {
        SortedSet<Integer> set=new TreeSet<>();
        System.out.println("enter number:");
        Scanner sc=new Scanner(System.in);
        int num=sc.nextInt();
        for(int i=0;i<num;i++)
            set.add(sc.nextInt());
        System.out.println(set);
    }
}
