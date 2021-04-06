import java.sql.*;
// Created by Denizcan Özpınar
public class main {
    public static Connection conn;


    public static void main(String[] args) throws SQLException {


    sqlManager manager = sqlManager.getInstance();
    GuiManager gui = new GuiManager();
    dbStartState st = new dbStartState();
    Context context = new Context();
    st.doAction(context);

    gui.splashScreen();
    GuiManager.setConnectionStat(sqlManager.getState());
    conn = manager.DBConnection(context);

    GuiManager.setConnectionStat(sqlManager.getState());
    GuiManager.Update_table(GuiManager.infoTable,conn);
    GuiManager.setConnectionStat(sqlManager.getState());



    }
}