package mypackage.utils.files;

import java.util.Comparator;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.TreeSet;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public interface I_Archivos {

    default void print() {
        System.out.println(getText());
    }

     String getText();

    void setText(String text);
    
    default void clear(){
        setText("");
    }

    void append(String text);

    default void addLine(String line) {
        append("\n"+line );
    }

    default void addLines(List<String> lines) {
        lines.forEach(this::addLine);
    }

    Stream<String> getStream();

    default List<String> getAll() {
        return this.getStream().collect(Collectors.toList());
    }

    default List<String> getByFilter(String filter) {
        return this
                .getStream()
                .filter(archivo -> archivo
                .toLowerCase()
                .contains(filter.toLowerCase()))
                .collect(Collectors.toList());
    }

    default List<String> getSortedLines(){
        return this
                .getStream()
                .sorted(Comparator.reverseOrder())
                .collect(Collectors.toList());
    }

    default List<String> getReversedSortedLines(){
        return this
                .getStream()
                .sorted(Comparator.reverseOrder())
                .collect(Collectors.toList());
    }

    default LinkedHashSet<String> getLinkedHashSetLines(){
        LinkedHashSet<String> set= new LinkedHashSet();
        set.addAll(getAll());
        return set;
                
    }

    default TreeSet<String> getTreeSetLines(){
        TreeSet<String> set= new TreeSet();
        set.addAll(getAll());
        return set;
    }

    
    default void remove(String line){
        List<String>list=getAll();
        list.remove(line);
        clear();
        addLines(list);
    }

}
