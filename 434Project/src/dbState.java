
public class dbState implements State {

    public void doAction(Context context){

        System.out.println("DB connected");
        context.setState(this);
    }

    @Override
    public String toString(){
        GuiManager.setConnectionStat("DB is connected");
        return "DB is connected";
    }
}








