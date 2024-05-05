let data = [
    {
        id: 1,
        name: "John",
        age: 25,
    },
    {
        id: 2,
        name: "Jane",
        age: 22,
    },
    {
        id: 3,
        name: "Doe",
        age: 30,
    }
];


//Consultar api
function getData(){

    return new Promise((resolve, reject) => {
        setTimeout(function(){
            if(false){
                resolve(data); //Return data
            }
            else{
                reject('Error');
            }
        }, 2000);
    });


}

//Funcion asincrona (hace lo mismo que then y catch)
async function fetchData(){

    try {
        let response = await getData(); //Se espera a que se resuelva la promesa
        console.log(response);
    } catch (error) {
        console.log(error);
    }
}

fetchData();

// let response = getData();

// response.then((data) => {
//     console.log(data);
// }).catch((error) => {
//     console.log(error);
// })

console.log('Continua el programa');

//Peticion HTTP
fetch('https://jsonplaceholder.typicode.com/users') //Devuelve una promesa
    .then(response => response.json()) //Devuelve una promesa nuevamente pero serializada
    .then( data => console.log(data)); // A ese data en json ya la podemos imprimir
