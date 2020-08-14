package mypackage.test;

import java.sql.Connection;
import java.sql.SQLException;
import java.util.Scanner;
import mypackage.connector.Connector;
import java.sql.Statement;
import java.sql.ResultSet;

public class TestConnector {

    public static void main(String[] args) throws SQLException {
        /*
        Connection conexionPrueba = Connector.getConnection();//Asignamos a la variable la conexion ya creada
        
        Statement declaracion=conexionPrueba.createStatement();//El Statement crea un objeto que modela a una sentencia sql
        
        String query="INSERT INTO cursos(titulo, profesor, dia, turno)"
                + " VALUES('JAVA','MARTINEZ','VIERNES','NOCHE')";//Creamos nuestra consulta a la db(En este caso agregamos)
        
        declaracion.execute(query);//Ejecutamos la query creada desde nuestra declaracion
        */
        
        //Todo lo anterior resumido en lo siguiente
        Connector
                .getConnection()
                .createStatement()//Para consultas preparadas
                .execute("INSERT INTO cursos(titulo,profesor,dia,turno)"
                + " VALUES('JAVA','MARTINEZ','VIERNES','NOCHE')");//El .ejecute no retorna un conjunto de resultados 
        
        
        
        //Un select nos devuelve un objeto ResultSet(Conjunto de registros)
        ResultSet rs=
                Connector
                    .getConnection()
                    .createStatement()
                    .executeQuery("SELECT * FROM cursos");
        
        //Recorremos el resultSet(Se recorre con while)
        //el metodo next() nos devuelve un booleano indicandonos si hay un proximo registro y nos corre
        //el apuntador a ese proximo registro
        while(rs.next()){
            System.out.println(
                    rs.getInt("id")+", "+
                    rs.getString("titulo")+", "+
                    rs.getString("profesor")+", "+
                    rs.getString("dia")+", "+
                    rs.getString("turno")   
            );
        }
        
        
        
    }

}
