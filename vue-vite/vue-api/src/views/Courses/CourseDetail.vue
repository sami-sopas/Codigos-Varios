<template lang="">
    <div>
        <h1>Detalle del curso: {{ course.title }} con ID: {{ $route.params.id}}</h1>

        <p>{{ course.description }}</p>

        <p>Categoria: {{ course.category }}</p>

        <!-- EDITAR -->
        <RouterLink :to="{ name: 'CourseEdit', params: { id: course.id} }">Editar curso</RouterLink>
    </div>
</template>

<script>
export default {

    data() {
        return {
            course: {}
        }
    },

    created() {
        this.getCourse();
    },

    methods: {
        getCourse(){
            this.axios.get('https://fakestoreapi.com/products/' + this.$route.params.id)
                .then(response =>  {
                    this.course = response.data;
                })
                .catch(error =>  {
                    console.log(error);
                });
        }
    }
}
</script>

<style lang="">
    
</style>