package slips;

class covid extends Thread{
    @Override
    public void run() {
        for(int i=0;i<10;i++){
            System.out.println("Covid19");
        }
    }
}

class lock extends Thread{
    @Override
    public void run() {
        for(int i=0;i<20;i++){
            System.out.println("Lockdown2020");
        }
    }
}
class vacc extends Thread{
    @Override
    public void run() {
        for(int i=0;i<30;i++){
            System.out.println("VACCINATED2021");
        }
    }
}

public class covid1 {
    public static void main(String[] args) {
        covid c=new covid();
        lock l=new lock();
        vacc v=new vacc();

        c.start();
        l.start();
        v.start();
    }

}
