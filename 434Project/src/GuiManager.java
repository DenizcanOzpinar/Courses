
import net.proteanit.sql.DbUtils;
import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowEvent;
import java.sql.*;


public class GuiManager extends javax.swing.JFrame {
    public static JTable infoTable;

    private JScrollPane pane;
    protected static JLabel connectionStat;
    protected static JTextField enterDeleteId;
    public static JTextField barField;
    protected static Control control;



    public void createGui(){
        GridLayout layout = new GridLayout(0,1);
        GridLayout layout1 = new GridLayout(0,3);
        control = new Control();
        JFrame frame = new JFrame("Store");
        connectionStat = new JLabel();
        JPanel lowerPanel = new JPanel();
        JPanel middlePanel = new JPanel();
        JLabel delteLabel = new JLabel("Enter id to delete the product :");
        JLabel barcodeLabel = new JLabel("Enter id of an item to create the barcode");
        barField = new JTextField();
        barField.setColumns(10);
        JButton barButton = new JButton("Create");
        barButton.addActionListener(control);


        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(720,640);
        JButton addButton = new JButton("add product");
        JButton refreshButton = new JButton("refresh");
        refreshButton.addActionListener(control);
        JPanel mainPanel = new JPanel();
        addButton.addActionListener(control);
        infoTable = new JTable();
        pane = new JScrollPane(infoTable,JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
        pane.setVisible(true);
        add(pane);


        enterDeleteId = new JTextField();
        enterDeleteId.setColumns(10);
        JButton deleteButton = new JButton("delete");


        deleteButton.addActionListener(control);


        mainPanel.add(connectionStat);

        lowerPanel.add(addButton);
        lowerPanel.add(refreshButton);
        middlePanel.setLayout(layout1);
        middlePanel.add(delteLabel);
        middlePanel.add(enterDeleteId);
        middlePanel.add(deleteButton);
        middlePanel.add(barcodeLabel);
        middlePanel.add(barField);
        middlePanel.add(barButton);

        mainPanel.add(pane);
        mainPanel.setLayout(layout);
        frame.add(mainPanel);
        mainPanel.add(middlePanel);
        mainPanel.add(lowerPanel);

        frame.setVisible(true);

    }





    public static void setConnectionStat(String str) {
        connectionStat.setText(str);
    }

    public JTable getInfoTable() {
        return infoTable;
    }
    protected static JTextField nameField;
    protected static JTextField descField;
    protected static JTextField quantField;
    protected static JTextField providerField;
    protected static JTextField priceField;
    protected static JTextField pquantField;
    protected static JTextField ppriceField;
    protected static JTextField placeField;


    public static void addPage() {

        GridLayout layout = new GridLayout(0,2);
        JFrame page = new JFrame("add product");
        page.setSize(640,640);
        JPanel mainPanel = new JPanel();

        mainPanel.setLayout(layout);
        mainPanel.setBackground(Color.LIGHT_GRAY);
        JLabel enterNameLabel = new JLabel("Enter name of product:");
        nameField = new JTextField();
        nameField.setColumns(10);
        mainPanel.add(enterNameLabel);
        mainPanel.add(nameField);

        JLabel enterDescLabel = new JLabel("Enter description of product:");
        descField = new JTextField();
        descField.setColumns(10);
        mainPanel.add(enterDescLabel);
        mainPanel.add(descField);

        JLabel enterQuantLabel = new JLabel("Enter quantity of product:");
        quantField = new JTextField();
        quantField.setColumns(10);
        mainPanel.add(enterQuantLabel);
        mainPanel.add(quantField);

        JLabel enterProviderLabel = new JLabel("Enter provider's name of product:");
        providerField = new JTextField();
        providerField.setColumns(10);
        mainPanel.add(enterProviderLabel);
        mainPanel.add(providerField);

        JLabel enterPriceLabel = new JLabel("Enter price of product:");
        priceField = new JTextField();
        priceField.setColumns(10);
        mainPanel.add(enterPriceLabel);
        mainPanel.add(priceField);

        JLabel enterPqunatLabel = new JLabel("Enter web stock of product:");
        pquantField = new JTextField();
        pquantField.setColumns(10);
        mainPanel.add(enterPqunatLabel);
        mainPanel.add(pquantField);

        JLabel enterPpriceLabel = new JLabel("Enter web price of product:");
        ppriceField = new JTextField();
        ppriceField.setColumns(10);
        mainPanel.add(enterPpriceLabel);
        mainPanel.add(ppriceField);

        JLabel enterPlaceLabel = new JLabel("Enter place of product:");
        placeField = new JTextField();
        placeField.setColumns(10);
        mainPanel.add(enterPlaceLabel);
        mainPanel.add(placeField);

        JButton confirm = new JButton("add");
        mainPanel.add(confirm);
        confirm.addActionListener(control);
        page.add(mainPanel);
        page.setVisible(true);
    }
    private void close() {
        WindowEvent winClosingEvent = new WindowEvent(this, WindowEvent.WINDOW_CLOSING);
        Toolkit.getDefaultToolkit().getSystemEventQueue().postEvent(winClosingEvent);
    }



    protected static void Update_table(JTable UserTable,Connection conn) {
        try {
            ResultSet rs = null;
            PreparedStatement pst = null;

            String sql = "select id,name,descr,quant,provider,price,place from store";
            pst = conn.prepareStatement(sql);
            rs = pst.executeQuery();
            UserTable.setModel(DbUtils.resultSetToTableModel(rs));


        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, e);
        }
    }




    public void splashScreen(){
        JWindow window = new JWindow();
        Image image = new ProxyImage("src/splash.png");


            window.getContentPane().add(new JLabel((new ImageIcon(image.display())),SwingConstants.CENTER));
            window.setBounds(500,180,400,330);
            window.setVisible(true);

        try {
            Thread.sleep(5000);

        }catch (InterruptedException e){
            e.printStackTrace();
        }
        window.setVisible(false);
        createGui();
        window.dispose();
    }


}

