<template lang="">
    <div>
        <h1>Bienvenido a mi tienda</h1>
        <!-- Recuperamos la informacion del estado (tienda)-->
        <p>Mi nombre es: {{ nombre }} y mi apellido es: {{ apellido }} con longitud de {{ sizeApellido }} letras</p>
    </div>
    
    <div>
        <h2>Contador</h2>
        <!-- Disparando funciones del mutador de store-->
        <button @click="decrement()">Disminuir</button>
          {{ count }}
        <button @click="increment()">Aumentar</button>
    </div>

    <div>
        <form @submit.prevent="changeNombreComponente()">
            <input type="text" v-model="nombreComponente">
            <button>Actualizar</button>
        </form>
    </div>
</template>
<script>
// import { mapState } from 'vuex';
// import { mapGetters } from 'vuex';
// import { mapMutations } from 'vuex';
// import { mapActions } from 'vuex';
import { createNamespacedHelpers } from 'vuex';

const { mapState, mapGetters, mapMutations, mapActions } = createNamespacedHelpers('user');

export default {
    data(){
        return {
            nombreComponente: '',
        }
    },

    // Propiedad computada para evitar estar escribiendo el sotre.state etc
    computed: {
        ...mapState(['nombre', 'apellido','count']), //Creamos las propiedades computadas nombre y apellido

        ...mapGetters(['sizeApellido']) //Creamos la propiedad computada sizeApellido, del modulo user

        //Y aqui podriamos seguir definiendo mas propiedades computadas propias
        // sizeApellido() {
        //     return this.$store.getters.sizeApellido
        // }
      },

    //Metodos que desencadenen la accion del $store.commit
    methods: {
        ...mapMutations(['decrement', 'increment']),
        ...mapActions(['changeNombre','confirmationChangeNombre']),

        //El .then es cuando la promesa del store se resuelve
        changeNombreComponente(){
            this.confirmationChangeNombre(this.nombreComponente).then(() => {
                this.nombreComponente = ''
            });
        },

        //Se elimina porque ya se mapeo
        // changeNombre(nombre){
        //     //Ejecutar accion del store
        //     this.$store.dispatch('changeNombre',nombre);
        // }

        //Este codigo se ahorra con el mapMutations
        // decrement(){
        //     this.$store.commit('decrement')
        // },
        // increment(){
        //     this.$store.commit('increment')
        // }
    }
}
</script>
<style lang="">
    
</style>