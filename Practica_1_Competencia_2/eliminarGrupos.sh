#!/bin/bash

eliminarGrupo(){
ELIMINADO=0

echo "Introduce el nombre del grupo que deseas eliminar: "
eval nombreGrupo="$1"
	sudo groupdel $grupo
	if [ $? -eq $ELIMINADO ]
			then
			echo "El grupo [ $grupo ] fue eliminado correctamente."
			else
			echo "El grupo [ $grupo ] no pudo ser eliminado."
fi
}