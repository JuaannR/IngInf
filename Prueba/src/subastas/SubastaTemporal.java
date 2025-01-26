package subastas;

import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;

public class SubastaTemporal extends SubastaLimitada {
    private final LocalDateTime fechaVencimiento;

    public SubastaTemporal(String nombreProducto, String propietario, int duracionHoras) {
        super(nombreProducto, propietario, duracionHoras * 2); // Máximo de pujas es el doble de las horas
        this.fechaVencimiento = LocalDateTime.now().plusHours(duracionHoras);
    }

    @Override
    public boolean pujar(String pujador, double cantidad) {
        if (LocalDateTime.now().isBefore(fechaVencimiento)) {
            return super.pujar(pujador, cantidad);
        }
        return false;
    }

    public long getHorasRestantes() {
        return ChronoUnit.HOURS.between(LocalDateTime.now(), fechaVencimiento);
    }

    @Override
    public boolean ejecutar() {
        if (LocalDateTime.now().isAfter(fechaVencimiento)) {
            return super.ejecutar();
        }
        return false;
    }
}
