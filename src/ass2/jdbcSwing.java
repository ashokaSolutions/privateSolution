package ass2;

import javax.swing.*;
import javax.xml.transform.Result;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class jdbcSwing {
    JFrame f;
    JTextField rollTxt,nameTxt,perTxt;
    JButton add,display;
    String[][] data=new String[5][5];
    String[] col={"roll","name","percentage"};

    jdbcSwing(){
        f=new JFrame();
        rollTxt=new JTextField();
        nameTxt=new JTextField();
        perTxt=new JTextField();

        add=new JButton("add");
        display=new JButton("display");

        rollTxt.setBounds(10,10,60,20);
        nameTxt.setBounds(75,10,60,20);
        perTxt.setBounds(140,10,60,20);
        add.setBounds(75,35,60,20);
        display.setBounds(65,70,90,20);

        actions();

        f.add(rollTxt);
        f.add(nameTxt);
        f.add(perTxt);
        f.add(add);
        f.add(display);

        f.setSize(300,300);
        f.setLayout(null);
        f.setVisible(true);
    }

    void actions(){
        add.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(nameTxt.getText()=="" || perTxt.getText()=="" || rollTxt.getText()=="" ){
                    System.out.println("please insert values");
                }else{
                    try{
                        Class.forName("com.mysql.cj.jdbc.Driver");
                        String url="jdbc:mysql://localhost:3306/studentDB";
                        String user="root";
                        String passwd="Darkone03.";
                        String query="show tables";

                        Connection conn=DriverManager.getConnection(url,user,passwd);
                        PreparedStatement preparedStatement=conn.prepareStatement("insert into student values (?,?,?)");
                        preparedStatement.setInt(1,Integer.parseInt(rollTxt.getText()));
                        preparedStatement.setString(2,nameTxt.getText());
                        preparedStatement.setFloat(3,Float.parseFloat(perTxt.getText()));

                        preparedStatement.executeUpdate();

                    }catch (Exception ex){
                        System.out.println(ex);
                    }
                }
            }
        });
        display.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

            }
        });
    }

    public static void main(String[] args) {
        new jdbcSwing();
    }
}
