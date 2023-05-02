package slips;

import java.util.Random;

// Online Java Compiler
// Use this editor to write, compile and run your Java code online
class square extends Thread{
    int x;
    square(int x){
        this.x=x;
    }
    public void run(){
        if(x%2==0){
            System.out.println(x+" sq:"+x*x);
        }
    }
}
class cub extends Thread{
    int x;
    cub(int x){
        this.x=x;
    }
    public void run(){
        if(x%2!=0){
            System.out.println(x+" cuba:"+x*x*x);
        }
    }
}
class num extends Thread{
    public void run(){
        Random rand=new Random();
        for(int i=0;i<10;i++){
            int x=rand.nextInt(100);
            System.out.println(x+"is number");
            square s=new square(x);
            s.start();
            cub c=new cub(x);
            c.start();
            try{
                Thread.sleep(1000);
            }catch(Exception e){
                System.out.print(e);
            }
        }
    }
}
public class runnacle{
    public static void main(String[] args){
        num x=new num();
        x.start();
    }
}
