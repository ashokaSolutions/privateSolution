package ass1.setA.setB;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.HashMap;
import java.util.Map;

public class collectionGUI {
    JFrame frame;
    JTextField cityADD,codeADD,cityRemove,citySearch;
    JButton add,remove,search;
    JTextArea textArea;

    Map<String,Integer> map=new HashMap<String,Integer>();

    collectionGUI(){
        frame=new JFrame("city gui");
        cityADD=new JTextField("cityname");
        cityRemove=new JTextField("cityname");
        citySearch=new JTextField("cityname");
        codeADD=new JTextField("code");

        add=new JButton("Add");
        remove=new JButton("Remove");
        search=new JButton("Search");

        textArea=new JTextArea();
        textArea.setEditable(false);
        textArea.setBounds(10,10,70,90);

        cityADD.setBounds(100,10,75,20);
        codeADD.setBounds(180,10,75,20);

        cityRemove.setBounds(100,60,75,20);
        citySearch.setBounds(180,60,75,20);

        add.setBounds(130,35,60,20);
        search.setBounds(100,80,60,20);
        remove.setBounds(160,80,60,20);

        frame.add(textArea);
        frame.add(cityADD);
        frame.add(codeADD);
        frame.add(add);
        frame.add(cityRemove);
        frame.add(citySearch);
        frame.add(remove);
        frame.add(search);

        actions();

        frame.setSize(300,300);
        frame.setLayout(null);
        frame.setVisible(true);
    }

    public void actions(){
        add.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(cityADD.getText()=="" || codeADD.getText()==""){
                    textArea.setText("please provide input");
                }else{

                    map.put(cityADD.getText(),Integer.valueOf(codeADD.getText()));
                    System.out.println(map);
                }
            }
        });

        remove.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(cityRemove!=null){
                    if(map.containsKey(cityRemove.getText())){
                        map.remove(cityRemove.getText());
                    }else{
                        textArea.setText("City not found");
                    }
                }else{
                    textArea.setText("please enter value to remove");
                }
            }
        });

        search.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(citySearch!=null){
                    if(map.containsKey(citySearch.getText())){
                        textArea.setText(citySearch.getText()+" "+map.get(citySearch.getText()));
                    }else{
                        textArea.setText("city not found");
                    }
                }
            }
        });
    }
    public static void main(String[] args) {
        new collectionGUI();
    }

}
