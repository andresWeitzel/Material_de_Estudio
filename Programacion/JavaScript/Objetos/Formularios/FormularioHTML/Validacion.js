window.onload = iniciar;

function iniciar() {
    document.getElementById("enviar").addEventListener('click', validar, false);

}

//En caso de que la validacion del elemento sea incorrecta hace de una funcion error al que lepasamos una funcin error y nos devuelve e un falso
function validanombre() {
    var elemento = document.getElementById("nombre");
    if (!elemento.checkValidity()) {
        //Comprobacion de caracteres ingresados
        if (elemento.validity.valueMissing) {
            error2(elemento, "Debe introducir un nombre ");
        }
        //En caso de que no coincida cpon el error le incluimos un mensaje 
        if (elemento.validity.patternMismatch) {
            error2(elemento, "El nombre debe tener entre 2 y 20 caracteres")
        }

        return false;

    }
    return true;
}

function validaedad() {
    var elemento = document.getElementById("edad");
    if (!elemento.checkValidity()) {
        if (elemento.validity.valueMissing) {
            error2(elemento, "Debes introducir una edad");
        }
        //Este if es si sobrepasamos el rango mostramos el siguiente mensaje
        if (elemento.validity.rangeOverflow) {
            error2(elemento, "tu edad debe ser menor de 100");
        }
        if (elemento.validity.rangeUnderflow) {
            error2(elemento, "tu edad debe ser mayor que 18");
        }

        return false;

    }
    return true;

}


function validatelefono() {
    var elemento = document.getElementById("telefono");
    if (!elemento.checkValidity()) {
        if (elemento.validity.valueMissing) {
            error2(elemento, "Debe introducir un telefono");
        }
        //En caso de que no coincida cpon el error le incluimos un mensaje 
        if (elemento.validity.patternMismatch) {
            error2(elemento, "El telefono debe tener 9 numeros")
        }

        return false;

    }
    return true;

}

function validar(e) {
    borrarError(); //le pasamos esta funcion hecha mas abajo para que limpie datos
    if (validanombre() && validaedad() && validatelefono() && confirm("Pulsa aceptar si deseas enviar el formulario")) {
        return true
    } else {
        e.preventDefault(); //Evitamos que se envia el formulario
        return false;
    }

}

//Si se produced un error de validacion captura el id mensaje_error del id del parrafo(p) del texto en la paqgina Formulario1.1.html y nos sobreescribe un mensaje por defecto(validationMessage).
function error(elemento) {
    document.getElementById("mensaje_error").innerHTML = elemento.validationMessage;
    elemento.className = "error"; //Le indicamos que al elemento se le adjunte la clase error predefinido en el css de nuestra pagina
    elemento.focus(); //esto es para maqetar el mensaje de errror
}

function error2(elemento, mensaje) {
    document.getElementById("mensaje_error").innerHTML = mensaje;
    elemento.className = "error";
    elemento.focus();
}


//  Esto es para quitar todas las clases error de todos los inputs para que cada vez que pulsamos en enviar se borren
function borrarError() {
    var formulario = document.forms[0];
    for (var i = 0; i < formulario.elements.length; i++) {
        formulario.elements[i].className = "";

    }
}