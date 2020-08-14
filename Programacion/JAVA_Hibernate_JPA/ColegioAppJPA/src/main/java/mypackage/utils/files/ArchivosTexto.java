package mypackage.utils.files;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.stream.Stream;

public class ArchivosTexto implements I_Archivos {

    private File file;

    public ArchivosTexto(File file) {
        this.file = file;
    }

    public ArchivosTexto(String file) {
        this.file = new File(file);
    }

    @Override
    public String getText() {
        int car;

        //String texto="";
        StringBuilder stringBuilder = new StringBuilder();

        try ( FileReader in = new FileReader(file);) {
            while ((car = in.read()) != -1) {
                //texto+=(char)car;
                stringBuilder.append((char) car);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return stringBuilder.toString();
    }

    @Override
    public void setText(String text) {
        try ( FileWriter in = new FileWriter(file);) {
            in.write(text);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void append(String text) {
        try ( FileWriter in = new FileWriter(file, true);) {//No borra el contenido del archivo
            in.write(text);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public Stream<String> getStream() {
        try {
            return new BufferedReader(new FileReader(file)).lines();//Variable anonima!

        } catch (Exception e) {
            return null;

        }
    }

}
