
package mypackage.utils.swing;

import java.lang.reflect.Field;
import java.util.List;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;


public class Table <E>{
    public void cargar(JTable table, List<E> list){
        if(table==null){
            return;
        }
        DefaultTableModel defaultTableModel=new DefaultTableModel();
        //Cargara por default la tabla
        table.setModel(defaultTableModel);
        
        if(list==null || list.isEmpty()){
            return;
        }
        //Primer objeto de la lista
        E e=list.get(0);
        //Usamos api reflect, apuntamos a api stream
        Field[] campos=e.getClass().getDeclaredFields();
        //recorremos lalista de campos, y el nombre de cada uno lo agrego como columna del defaultTable..
        for(Field f:campos){
            defaultTableModel.addColumn(f.getName());
        }
        //Recorremos la lista campo por campo de cada elemento
        for(E ee:list){
            Object[] registro=new Object[campos.length];
            for(int a=0;a<campos.length;a++){
                //objeto del tipo campo nombre de nombre f, 
                Field f=campos[a];
                String metodo=
                        "get"
                        +f.getName().substring(0,1).toUpperCase()
                        +f.getName().substring(1);
                System.out.println(metodo);
                try{
                    //Al ser un metodo get no posee parametros de entrada, lo
                    //invovo sobre el objeto que estoy recorriendo de lalista
                    registro[a]=e.getClass().getMethod(metodo, null).invoke(ee, null);
                    
                }catch(Exception ex){
                    ex.printStackTrace();
                }
                
            }
            defaultTableModel.addRow(registro);
        }
        
    }

}
