<script setup>
import HelloWorld from './components/HelloWorld.vue'
import TheWelcome from './components/TheWelcome.vue'
import MyCounter from './components/MyCounter.vue'
import MyStore from './components/MyStore.vue'
</script>

<template>
  <header>
    <img alt="Vue logo" class="logo" src="./assets/logo.svg" width="125" height="125" />

    <p>
    <strong>Current route path:</strong> {{ $route.fullPath }}
  </p>
  <nav>
    <RouterLink :to="{name: 'home'}">Go to Home</RouterLink>
    <RouterLink :to="{name: 'about'}">Go to About</RouterLink>
    <RouterLink :to="{name: 'blog'}">Go to Blog</RouterLink>
  </nav>

    <div class="wrapper">
      <!-- <HelloWorld msg="Curso Vue.js" /> -->
      <h1>Titulo principal</h1>
      <MyCounter />
    </div>
  </header>

  <main>
    <!-- <TheWelcome /> -->
    <!-- Hello world-->
    <HelloWorld msg="Hola Vue" />  
    <!-- end: Hello worlds-->

    <!-- MyStore -->
    <MyStore />
    <!-- end: MyStore -->
    
    <router-view /> <!-- Aquí es donde se renderizará el componente de la ruta actual -->
  </main>
</template>

<style scoped>
header {
  line-height: 1.5;
}

.logo {
  display: block;
  margin: 0 auto 2rem;
}

@media (min-width: 1024px) {
  header {
    display: flex;
    place-items: center;
    padding-right: calc(var(--section-gap) / 2);
  }

  .logo {
    margin: 0 2rem 0 0;
  }

  header .wrapper {
    display: flex;
    place-items: flex-start;
    flex-wrap: wrap;
  }
}
</style>
