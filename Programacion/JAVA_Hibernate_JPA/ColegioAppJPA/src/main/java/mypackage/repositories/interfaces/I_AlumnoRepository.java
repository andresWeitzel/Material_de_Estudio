package mypackage.repositories.interfaces;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import mypackage.entities.persistence.Alumno;
import mypackage.entities.persistence.Curso;

public interface I_AlumnoRepository {

    void save(Alumno alumno);  //INSERT

    void remove(Alumno alumno); //DELETE

    void update(Alumno alumno); //UPDATE

    List<Alumno> getAll();      //SELECT
    
    default Stream<Alumno> getStream(){
        return getAll().stream();
    }

    default Alumno getById(int id){
        return getStream()
                .filter(a->a.getId()==id)
                .findAny().orElse(new Alumno());
    }
    
    default List<Alumno> getLikeApellido(String apellido){
        if(apellido==null){
            return new ArrayList<Alumno>();
        }
        return getStream()
                .filter(a->a.getApellido().toLowerCase().contains(apellido.toLowerCase()))
                .collect(Collectors.toList());
    }   
    
    default List<Alumno> getByCurso(Curso curso){
         if (curso == null) {
            return new ArrayList<Alumno>();
        }
         
        return getStream()
                .filter(a->a.getIdCurso()==curso.getId())
                .collect(Collectors.toList());
        
    }
}
