<template lang="">
    <!-- Recibiendo parametro -->
    <div v-if="$route.params.userId">
        <h1>Aqui podras ver el detalle del usuario con ID: {{ userId }}</h1>
    </div>

    <!-- Sin recibir parametro -->
    <div v-else>
        <h1>Aqui podras ver la lista de usuarios</h1>
    </div>

    <nav>
        <!-- Se accede a la ruta mediante su atributo name y se le pasa el parametro de la url ejem: /user/userId/profile-->
    <RouterLink :to="{ name: 'UserIndex', params: {userId: $route.params.userId}}">Contenido por defecto</RouterLink>
    <RouterLink :to="{ name: 'UserProfile', params: {userId: $route.params.userId} }">Perfil</RouterLink>
    <RouterLink :to="{ name: 'UserCourses', params: {userId: $route.params.userId} }">Cursos</RouterLink>

    <!-- Aqui se cargara el componente de las rutas hijas (ProfileView,CoursesView & IndexView)-->
    <router-view />
  </nav>
</template>
<script>
export default {
    //Recibimos los props, de esta manera podemos dejar de usar $route.params a solo userId
    props: ['userId']
}
</script>
<style lang="">
    
</style>