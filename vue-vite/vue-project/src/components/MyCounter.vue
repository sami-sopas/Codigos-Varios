<template>
    <h1>Hola desde el componente counter</h1>

    <button @click="decrement" :disabled="counter === 0">
        -
    </button>
    {{ counter }}
    <button @click="increment">
        +
    </button>
</template>

<script setup>
import { ref } from 'vue';

let counter = ref(0);

const increment = () => {
    counter.value++;
}

const decrement = () => {
    counter.value--;
}
</script>

<!-- Scoped hace que los estilos SOLO APLIQUEN PARA EL CODIGO DENTRO DEL TEMPLATE-->
<style scoped>
    h1 {
        color: red;
    }
</style>
