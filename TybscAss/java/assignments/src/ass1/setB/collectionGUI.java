package ass1.setB;
import javax.swing.*;
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
        textArea.setBounds(10,10,100,140);

        cityADD.setBounds(150,10,90,20);
        codeADD.setBounds(245,10,90,20);

        cityRemove.setBounds(150,60,90,20);
        citySearch.setBounds(245,60,90,20);

        add.setBounds(190,35,90,20);
        search.setBounds(150,80,90,20);
        remove.setBounds(245,80,90,20);

        frame.add(textArea);
        frame.add(cityADD);
        frame.add(codeADD);
        frame.add(add);
        frame.add(cityRemove);
        frame.add(citySearch);
        frame.add(remove);
        frame.add(search);

        actions();

        frame.setSize(400,400);
        frame.setLayout(null);
        frame.setVisible(true);
    }

    public void actions(){
        add.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                textArea.setText("");
                if(cityADD.getText()=="" || codeADD.getText()=="" ){
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
