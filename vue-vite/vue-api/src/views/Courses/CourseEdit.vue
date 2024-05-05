<template lang="">
    <div>
        <h1>Aqui podras editar un curso</h1>

    <!-- FORM UPDATE -->
    <form @submit.prevent="updateCourse">
        <div>
            <label for="title">Titulo</label>
            <br>
            <input v-model="course.title" id="title" type="text" placeholder="Ingrese el titulo del curso">
        </div>

        <br>

        <div>
            <label for="descripction">Descripcion</label>
            <br>
            <textarea v-model="course.description" id="descripction" type="text" placeholder="Ingrese la descripcion del curso"></textarea>
        </div>

        <br>
        
        <div>
            <label for="category">Categoria</label>
            <br>
            <select id="category" v-model="course.category">
                <option value="">Seleccione una categoria</option>
                <option 
                    v-for="category in categories" 
                    :key=" 'categoy-' + category"
                    :value="category">
                    {{ category }}
                </option>
            </select>
        </div>

        <br>

        <button type="submit">Guardar</button>

    </form>

    Curso: {{ course }}

    </div>
</template>

<script>
export default {
    data() {
        return {
            course: { 
                title: '',
                description: '',
                category: ''
            },
            categories: []
        }
    },
    created() {
        this.getCourse();
        this.getCategoties();
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
        },
        getCategoties(){
            this.axios.get('https://fakestoreapi.com/products/categories')
                .then(response =>  {
                    this.categories = response.data;
                })
                .catch(error =>  {
                    console.log(error);
                });

        },
        //PETICION PUT/PATCH
        updateCourse(){ //Se le pasa el id del producto, y el objeto con los datos a actualizar
            this.axios.put('https://fakestoreapi.com/products/' + this.$route.params.id, this.course)
                .then(response =>  {
                    console.log(response);
                    this.$router.push({ name: 'CourseDetail', params: { id: this.$route.params.id } }); //Redireccionar a la vista de detalle
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