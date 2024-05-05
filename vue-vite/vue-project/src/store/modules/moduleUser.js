export const moduleUser = {

    namespaced: true, //Para que no se mezclen los nombres de las mutaciones, getters, actions etc

    state: {
        nombre: 'Juan',
        apellido: 'Perez',
    },
    //Getters, recibe los states y apartir de ahi es como si  realizara una propiedad computada
    getters: {
        sizeApellido(state) {
            return state.apellido.length;
        }
    },
    //Encargados de modificar los states de la tienda
    mutations: {
        changeNombre(state, nombre){
            state.nombre = nombre;
        },
    },
    //Modificar los states pero a nivel de BD, peticiones asincronas
    actions: { 
        changeNombre({ commit }, nombre) { //Con context accedemos a mutuaciones, getters etc,

            return new Promise((resolve) => {
                setTimeout(() => {
                    //console.log('Actualizado en BD');
                    //Actualizar el state, se llama al metodo del mutator
                    commit('changeNombre', nombre) //con { commit } lo deestructuramos para no hacer context.commit
                    resolve(); //Promesa resuelta
                }, 2000)
            })
        },

        async confirmationChangeNombre({ dispatch }, nombre) {
            await dispatch('changeNombre', nombre); //Se espera a que la promesa changeNombre se resuelba

            console.log('Actualizado en BD');
        }

    },
}
