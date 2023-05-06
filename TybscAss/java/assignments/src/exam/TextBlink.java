
class edit extends Thread{
    JLabel j=new JLabel();
    edit(JLabel j){
        this.j=j;
    }

    @Override
    public void run() {
        for(int i=0;i<20;i++){
            j.setText("hello");
            try{
                Thread.sleep(1000);
            }catch (Exception e){
                System.out.println(e);
            }
            j.setText("");
        }
    }
}
public class blink {
    Frame f;
    JLabel label;

    blink(){
        f=new Frame();
        label=new JLabel();

        label.setBounds(10,10,30,30);

        f.add(label);

        edit obj=new edit(label);
        f.setSize(300,300);
        f.setVisible(true);
        f.setLayout(null);
    }

    public static void main(String[] args) {
        new blink();
    }
}
