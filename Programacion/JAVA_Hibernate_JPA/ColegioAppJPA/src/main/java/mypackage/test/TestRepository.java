package mypackage.test;

import mypackage.connector.Connector;
import mypackage.entities.persistence.Alumno;
import mypackage.entities.persistence.Curso;
import mypackage.enums.Dia;
import mypackage.enums.Turno;
import mypackage.repositories.interfaces.I_AlumnoRepository;
import mypackage.repositories.interfaces.I_CursoRepository;
import mypackage.repositories.jdbc.AlumnoRepository;
import mypackage.repositories.jdbc.CursoRepository;

public class TestRepository {

    public static void main(String[] args) {

        // * * * * * * TESTEO CLASE CURSOREPOSITORY***********
        I_CursoRepository cursoRepository = new CursoRepository(Connector.getConnection());
        Curso curso = new Curso("PHP", "Romero", Dia.VIERNES, Turno.MAÑANA);
        cursoRepository.save(curso);//La db le coloca el id y lo recibimos cpor referencia
        System.out.println(curso);

        System.out.println("\n--Borramos el campo con el id que le pasemos como parametro ---");
        cursoRepository.remove(cursoRepository.getById(1));

        System.out.println("\n---Todos los campos de nuestra tabla  curso-- "); cursoRepository.getAll().forEach(System.out::println);
          System.out.println("\n---Todos los campos de tipo titulo que posean"
                + " en su comienzo las siguientes iniciales en la tabla curso---");
        cursoRepository.getLikeTitulo("JA").forEach(System.out::println);

        System.out.println("\n---Actualizamos el campo que tenga el id  pasado--"); curso=cursoRepository.getById(10);
          if (curso != null && curso.getId() != 0) {//Que curso no sea null ni el id  sea cero
            curso.setProfesor("Ramirez");
            cursoRepository.update(curso);
        }

        //*******************TESTEO CLASE ALUMNOREPOSITORY***********
        I_AlumnoRepository alumnoRepository = new AlumnoRepository(Connector.getConnection());

        Alumno alumno = new Alumno("Marcos", "Gutierrez", 19, 2);

        alumnoRepository.save(alumno);
        alumnoRepository.save(new Alumno("Lucas", "Franco", 20, 3));
        alumnoRepository.save(new Alumno("Tomas", "Dominguez", 10, 3));
        alumnoRepository.save(new Alumno("Martina", "Gustamanet", 27, 3));
        alumnoRepository.save(new Alumno("Carla", "Celedon", 23, 2));
        alumnoRepository.save(new Alumno("Gustavo", "Rodriguez", 44, 2));

        System.out.println(alumno);

        System.out.println("\n---Todos los campos de nuestra tabla alumno---");
        alumnoRepository.getAll().forEach(System.out::println);

    }

}
