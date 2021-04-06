import net.proteanit.sql.DbUtils;
import net.sourceforge.barbecue.Barcode;
import net.sourceforge.barbecue.BarcodeException;
import net.sourceforge.barbecue.BarcodeFactory;
import net.sourceforge.barbecue.BarcodeImageHandler;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.sql.*;

public class Control implements ActionListener {



    private void delete_item(String id, Connection conn) throws SQLException {
        String deleteItem = "DELETE FROM store  WHERE id = "+Integer.parseInt(id);
        PreparedStatement delete = conn.prepareStatement(deleteItem, Statement.RETURN_GENERATED_KEYS);

        delete.executeUpdate();
        conn.commit();
    }

    protected static void Update_table(JTable UserTable,Connection conn) {
        try {
            ResultSet rs = null;
            PreparedStatement pst = null;

            String sql = "select id,name,descr,quant,provider,price,place from store";
            pst = conn.prepareStatement(sql);
            rs = pst.executeQuery();
            GuiManager.infoTable.setModel(DbUtils.resultSetToTableModel(rs));


        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, e);
        }
    }
    public static void AddItem(String name, String desc, int quant, String provider, double price, int pquant, double pprice, String place, String qevalue) throws SQLException {
        String addItem = "INSERT INTO store (name , descr,quant,provider,price,pquant,pprice,place,qevalue) VALUES (?,?,?,?,?,?,?,?,?)";
        PreparedStatement item = main.conn.prepareStatement(addItem, Statement.RETURN_GENERATED_KEYS);

        item.setString(1, name);
        item.setString(2, desc);
        item.setInt(3, quant);
        item.setString(4, provider);
        item.setDouble(5, price);
        item.setInt(6, pquant);
        item.setDouble(7,pprice);
        item.setString(8,place);
        item.setString(9,qevalue);

        item.executeUpdate();
        main.conn.commit();


    }


    @Override
    public void actionPerformed(ActionEvent e) {
        String ch = e.getActionCommand();

        if (ch == "delete"){
            try {
                delete_item(GuiManager.enterDeleteId.getText(),main.conn);
            } catch (SQLException sqlException) {
                sqlException.printStackTrace();
            }
            JFrame tmp = new JFrame("Message");
            JOptionPane.showMessageDialog(tmp, "Item deleted");
        }else if (ch == "refresh"){
            Update_table(GuiManager.infoTable,main.conn);
            System.out.println("Table updated");
        }else if (ch == "add product"){
            GuiManager.addPage();
        }else if (ch == "Create"){
            Barcode barcode = null;
            JFrame tmp = new JFrame("Message");
            try {
                barcode = BarcodeFactory.createCode128B(GuiManager.barField.getText());
            } catch (BarcodeException eee) {
                eee.printStackTrace();
            }

            try {
                File f = new File("barcodes/barcode"+GuiManager.barField.getText()+".png");

                BarcodeImageHandler.savePNG(barcode, f);
            } catch (Exception ee) {
                ee.printStackTrace();
            }
            JOptionPane.showMessageDialog(tmp, "File saved to barcodes folder successfully");
        }else if (ch == "add"){
            try {

                String qevalue = "0";

                AddItem(GuiManager.nameField.getText(),GuiManager.descField.getText(),Integer.parseInt(GuiManager.quantField.getText()),GuiManager.providerField.getText(),Double.parseDouble(GuiManager.priceField.getText()),Integer.parseInt(GuiManager.pquantField.getText()),Double.parseDouble(GuiManager.ppriceField.getText()),GuiManager.placeField.getText(),qevalue);
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
            System.out.printf("added");

        }


    }}

