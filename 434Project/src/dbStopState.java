public class dbStopState implements State{

    public void doAction(Context context){
        GuiManager.setConnectionStat("DB is not connected");
        System.out.println("DB is not connected");
        context.setState(this);
    }

    @Override
    public String toString(){
        GuiManager.setConnectionStat("DB is not connected");
        return "DB is not connected";
    }
}