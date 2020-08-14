
package mypackage.repositories.interfaces;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import mypackage.entities.persistence.Curso;


public interface I_CursoRepository {
    
    
    void save(Curso curso);  //INSERT

    void remove(Curso curso); //DELETE

    void update(Curso curso); //UPDATE

    List<Curso> getAll();      //SELECT

    default Stream<Curso> getStream() {//nos devuelve un stream, el usuario final debe filtrar
        return getAll().stream();
    }

    default Curso getById(int id) {//nos devuelve un objeto curso con el id pasado
        return getStream()
                .filter(c -> c.getId() == id)//Si ese curso tiene el iid que me ingresa como parametro
                .findAny().orElse(new Curso());//Nos devuelve un optional, si lo encuentra lo devuelve, y si no lo encuentra nos devuelve un curso vacio, evitamos el null
    }

    default List<Curso> getLikeTitulo(String titulo){ //busqueda de expresion con el titulo
        if (titulo == null) {
            return new ArrayList<Curso>();
        }
        return getStream()
                .filter(c -> c.getTitulo().toLowerCase().contains(titulo.toLowerCase()))
                .collect(Collectors.toList());//El stream que nos devuelve el filter lo pasamos a list que es lo que me pide como estandar el patron dao.

    }

    default List<Curso> getLikeTituloProfesor(String titulo, String profesor){//Hace la busqueda por titulo y por profesor 
        if (titulo == null || profesor==null) {
            return new ArrayList<Curso>();
        }
        return getStream()
                .filter(c->c.getTitulo().toLowerCase().contains(titulo.toLowerCase())
                        && c.getProfesor().toLowerCase().contains(profesor.toLowerCase()))
                .collect(Collectors.toList());
        
    }



}
