package parcial2_g2;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.Comparator;

public class Utils implements Comparator<Comunidad> {

    // Método para obtener las comunidades activas
    public Set<Comunidad> getActivas(List<Comunidad> comunidades) {
        HashSet<Comunidad> activas = new HashSet<Comunidad>();
        
        // Recorre la lista de comunidades
        for (Comunidad actual : comunidades) {
            // Si la comunidad es instancia de ComunidadActiva
            if (actual instanceof ComunidadActiva activa) {
                // Si tiene mensajes destacados, se añade a la lista de activas
                if (activa.getMensajesDestacados().size() > 0) {
                    activas.add(actual);
                }
            }
        }
        
        // Retorna el conjunto inmutable de comunidades activas
        return Collections.unmodifiableSet(activas);
    }

    // Método para comparar dos comunidades
    public int compare(Comunidad primera, Comunidad segunda) {
        // Compara la cantidad de mensajes en cada comunidad
        if (primera.getMensajes().size() > segunda.getMensajes().size()) {
            return -1;  // Si la primera tiene más mensajes, retorna -1
        } else if (primera.getMensajes().size() < segunda.getMensajes().size()) {
            return 1;  // Si la segunda tiene más mensajes, retorna 1
        }
        
        return 0;  // Si tienen la misma cantidad de mensajes, retorna 0
    }
}
