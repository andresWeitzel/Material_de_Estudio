//SELECCION DEL FORMULARIO



//Conociendo el id

var formulario = document.getElementById("miFormulario");

var formulario2 = document.forms["miFormulario"];



//Conociendo el número de formulario que es en la página

var formulario3 = document.getElementsByTagName("form")[0];

var formulario4 = document.forms[0];



//SELECCIONAR ELEMENTOS DE UN FORMULARIO

//.elements[] Devuelve un array con todos los input del formulario

//getElementById("idElemento") Devuelve un elemento con un id determinado

//getElementsByTagName("etiqueta") Devuelve un array con elementos de un tipo de etiqueta (input, select, etc.)

//getElementsByName("nombre") Devuelve un array con elementos que tienen el mismo nombre (por ejemplo, radiobutton).


//esto es para que una vez ques e haya cargado la pagina se pueda ejecutar el codigo de validacion
window.onload = iniciar; //Sin paréntesis, la funcion iniciar se construye mas adelante



function iniciar() {

    document.getElementById("enviar").addEventListener('click', validar, false);

}



function validaNombre() {

    var elemento = document.getElementById("nombre");

    limpiarError(elemento);

    if (elemento.value == "") {

        alert("El campo no puede ser vacío");

        error(elemento);

        return false;

    }

    return true;

}



function validaTelefono() {

    var elemento = document.getElementById("telefono");

    //El NaN nos valida a comparacion si es un numero(not and number)
    if (isNaN(elemento.value)) {

        alert("El campo teléfono tiene que ser numérico");

        return false;

    }

    return true;

}



function validaFecha() {

    var dia = document.getElementById("dia").value;

    var mes = document.getElementById("mes").value;

    var ano = document.getElementById("ano").value;



    var fecha = new Date(ano, mes, dia);

    if (isNaN(fecha)) {

        alert("Los campos de la fecha son incorrectos");

        return false;

    }

    return true;

}



function validaCheck() {

    var campoCheck = document.getElementById("mayor");

    if (!campoCheck.checked) {

        alert("Debes ser mayor de edad");

        return false

    }

    return true;

}



function validar(e) {

    if (validaNombre() && validaTelefono() && validaFecha() && validaCheck() && confirm("Pulsa aceptar si deseas enviar el formulario")) {

        return true;

    } else {

        e.preventDefault(); //evitar que se ejecute el evento("e") asociado a la accion

        return false;

    }

}



function error(elemento) { //Utilizamos esta funcion para marcar con un color la casilla del formulario que este con un error

    elemento.className = "error";

    elemento.focus();

}



function limpiarError(elemento) { //Utilizaremos esta funcion para limpiar una vez que haya desaparecido el error de alguna casilla del formulario
    elemento.className = "";

}