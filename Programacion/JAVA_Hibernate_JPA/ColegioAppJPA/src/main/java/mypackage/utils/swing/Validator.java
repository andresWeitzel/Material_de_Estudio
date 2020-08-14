package mypackage.utils.swing;


import javax.swing.JOptionPane;
import javax.swing.JTextField;

public class Validator {

    private JTextField txt;

    public Validator(JTextField txt) {
        this.txt = txt;
    }

    private boolean error(String msj) {
        txt.requestFocus();
        JOptionPane.showMessageDialog(txt, msj, "error", JOptionPane.ERROR_MESSAGE);
        return false;
    }

    public boolean length(int min, int max) {
        if (txt.getText().length() >= min && txt.getText().length() <= max) {
            return true;
        }
        return error("Los campos Titulo y Profesor deben tener entre" + min + " y " + max + " caracteres!!");

    }

    //Evaluamos que la edad sea un entero y tenga un determinado rango
    public boolean isInteger() {
        try {
            Integer.parseInt(txt.getText());
            return true;
        } catch (Exception e) {
            return error("El valor debe ser un numero entero!");
        }
    }
    //Sobrecarga, para que el valor este entre un min y un max
    public boolean isInteger(int min, int max){
        if(!isInteger()){
            return false;
        } 
        //Tomo el valor del campo y lo paso a un entero
        int valor=Integer.parseInt(txt.getText());
        
        if(valor >=min && valor <= max){
            return true;
        }
        return error("El valor debe estra comprendido entre "+min+" y "+max+" !!");
    }

}
