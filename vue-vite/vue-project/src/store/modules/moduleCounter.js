const moduleCounter = {

    namespaced: true,

    //Parecido al data de un componente, y sera un state
    state: {
        count: 1
    },
    //Encargados de modificar los states de la tienda
    mutations: {
        decrement(state){
            state.count--;
        },

        increment(state){
            state.count++;
        }
    },
}

export default moduleCounter;