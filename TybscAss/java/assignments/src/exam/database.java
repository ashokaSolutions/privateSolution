package slips;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

public class db_swing {
    Frame frame;
    JPanel panel;
    JLabel label1 ;
    JTextField textField1 ;
    JLabel label2 ;
    JTextField textField2 ;
    JLabel label3 ;
    JTextField textField3 ;
    JButton button ;
    public db_swing() {
        frame=new Frame();
        panel = new JPanel(new GridLayout(4, 2)); // 4 rows, 2 columnsJLabel label1 = new JLabel("Label 1");
         textField1 = new JTextField();
        label1 = new JLabel("Label 1");
        label2 = new JLabel("Label 2");
         textField2 = new JTextField();
        label3 = new JLabel("Label 3");
        textField3 = new JTextField();
         button = new JButton("Submit");
        panel.add(label1);
        panel.add(textField1);
        panel.add(label2);
        panel.add(textField2);
        panel.add(label3);
        panel.add(textField3);
        panel.add(button);
        frame.add(panel);
        frame.setSize(400, 200);
        frame.setVisible(true);
        actions();
    }

    void actions(){
        button.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                try{
                    Class.forName("org.postgresql.Driver");
                    Connection conn= DriverManager.getConnection("jdbc:postgresql://localhost:5432/testdb","postgres","sumedh");
                    PreparedStatement stmt = conn.prepareStatement("insert into Teacher values(?,?,?);");
                    int acc=Integer.parseInt(textField1.getText());
                    stmt.setInt(1,acc);
                    stmt.setString(2,textField2.getText());
                    stmt.setString(3, textField3.getText());
                    ResultSet rs=stmt.executeQuery();
                    while (rs.next()) {
                        System.out.println(rs.getString(2));
                        // or p.name=rs.getString("firstname"); by name of column
                    }
                } catch (Exception ex) {
                    throw new RuntimeException(ex);
                }

            }
        });
    }
    public static void main(String[] args) {
        new db_swing();
    }
}
