<script>
import { onBeforeMount, onMounted, onUnmounted, onUpdated, ref } from 'vue'

export default {
  props: {
    msg: {
      type: String,
      required: true
    }
  },
  setup() { //Lifecycle hooks
    let prueba = ref('Hola mundo')

    onBeforeMount(() => {
      console.log('beforeCreate');
      //prueba.value = 'Hola mundo desde beforeCreate' (No se imprime en la vista)
    });

    onMounted(() => {
      console.log('created');
      //prueba.value = 'Hola mundo desde onMounted' // ya se ve en la vista cambiado
    });

    onUpdated(() => {
      console.log('updated');
    });
    
    onUnmounted(() => {
      console.log('destroyed');
    });

    return {
      prueba
    }
  }
}
</script>

<template>
  <div class="greetings">
    <h1 class="green">{{ msg }}</h1>
    <h3>
      You’ve successfully created a project with: {{ prueba }}
    </h3>
    <button @click="prueba = 'Nuevo valor' ">Cambia valor prueba</button>
  </div>
</template>

<style scoped>
h1 {
  font-weight: 500;
  font-size: 2.6rem;
  position: relative;
  top: -10px;
}

h3 {
  font-size: 1.2rem;
}

.greetings h1,
.greetings h3 {
  text-align: center;
}

@media (min-width: 1024px) {
  .greetings h1,
  .greetings h3 {
    text-align: left;
  }
}
</style>
