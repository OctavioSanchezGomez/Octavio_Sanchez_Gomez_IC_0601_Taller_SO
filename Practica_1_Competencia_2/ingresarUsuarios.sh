#!/bin/bash
ROOT_UID=0
SUCCESS=0
# Run as root, of course. (this might not be necessary, because we have to run the script somehow with root anyway)
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi
file=$1
if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo con el listado de usuarios a agregar..."
   exit 1
fi
# Del archivo con el listado de usuarios a eliminar:
# Este es el formato:
# ejemplo
#    |
#    f1
#$f1 = username
ingresarUsuario(){
    username=$1
    password=$2
    userID=$3
    groupID=$4
    userIDInfo=$5
    home=$6
    comand=$7

    if grep $username /etc/passwd; then
        echo "El usuario $username ya esta creado"
    else
        echo "El usuario $username No encontrado"
        echo "Creando Usuario... "
        useradd -m $username
        useradd -p $password
        useradd -c $UserIDInfo
        useradd -s  $comand $username
        echo "$username:$password"  | chpasswd -md5
fi
}
while IFS=":" read -r f1 f2 f3 f4 f5 f6 f7
do
    ingresarUsuario $f1 $f2 $f3 $f4 $f5 $f6 $f7
done < $file
exit 0