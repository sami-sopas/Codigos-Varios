<template lang="">
    <div class="container">
        <h1>Listado de cursos</h1>
    
        <!-- Crear producto -->
        <div class="mb-4">
            <form @submit.prevent="saveCourse" class="">
                <div>
                    <label for="title">Titulo</label>
                    <br>
                    <input v-model="course.title" id="title" type="text" placeholder="Ingrese el titulo del curso" class="form-control">
                </div>
        
                <br>
        
                <div>
                    <label for="descripction">Descripcion</label>
                    <br>
                    <textarea v-model="course.description" id="descripction" type="text" placeholder="Ingrese la descripcion del curso" class="form-control"></textarea>
                </div>
        
                <br>
                
                <div>
                    <label for="category">Categoria</label>
                    <br>
                    <select id="category" v-model="course.category" class="form-control">
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
        
                <button class="btn btn-primary btn-sm" type="submit">Guardar</button>
        
            </form>
        </div>
    
        Curso: {{ course}}
    
        <br>

        <!-- Buscador-->
        <div class="mb-2">
            <h2>Buscador</h2>
            <input type="text" class="form-control" placeholder="Ingrese texto a buscar" >
        </div>
    
        <!-- Listado de cursos -->
        <ul>
            <li 
                class="mb-2"
                v-for="course in courses" 
                :key=" 'course-' + course.id">
                
                <RouterLink :to="{ name: 'CourseDetail', params: { id: course.id } }">
                    {{ course.title }}
               </RouterLink> 
                - 
            <button @click="deleteCourse(course.id)" class="btn btn-danger btn-sm">
                Eliminar
            </button>
            </li>
        </ul>
    
        Page: {{ page }}
    
        <!-- Limitar registros -->
        <div class="d-flex justify-content-center">
        <nav aria-label="...">
            <ul class="pagination">
                <li class="page-item" v-for="limit in limits">
                    <a 
                        class="page-link" 
                        @click="changeLimit(limit)"
                        style="cursor: pointer">
                        {{ limit }}
                    </a>
                </li>
            </ul>
        </nav>
        </div>
    </div>
    
</template>

<script>

import usePagination from '/src/composables/usePagination.js';

export default {
    //Metodo que se ejecuta antes del componente, composition API
    setup() {
        //Desestructurar lo que se exporta
        const { limits, page, changeLimit } = usePagination();

        return {
            limits,
            page,
            changeLimit
        }
    },

    data() {
        return {
            courses: [],
            categories: [],
            course: {
                'title': '',
                'description': '',
                'category': ''
            },
            per_page: 5,
        }
    },
    watch: {
        page() {
            this.per_page = this.page;
            this.getCourses();
        }
    },

    created() {
        this.getCourses();
        this.getCategories();
    },

    methods: {
        getCourses(){
            // this.axios.get('https://fakestoreapi.com/products?limit=' + this.per_page) //Otra forma de pasar los parametros de la url
            this.axios.get('https://fakestoreapi.com/products', {
                params: {
                    limit: this.per_page
                }
            
            })
            .then(response =>  {
                this.courses = response.data;
            })
            .catch(error =>  {
                console.log(error);
            });
        },
        getCategories() {
            this.axios.get('https://fakestoreapi.com/products/categories')
                .then(response =>  {
                    this.categories = response.data;
                })
                .catch(error =>  {
                    console.log(error);
                });
        },
        //Peticion POST, mandamos el objeto course que ya trae los atributos escritos en el form
        saveCourse() {
            this.axios.post('https://fakestoreapi.com/products', this.course)
                .then(response =>  {
                    this.courses.push(response.data); //La respuesta de la api, nos retorna el curso creado, lo agregamos a nuestro array actual
                    console.log(response);
                    this.cleanInputs();
                })
                .catch(error =>  {
                    console.log(error);
                });
        },
        //Peticion DELETE
        deleteCourse(id) {
            this.axios.delete('https://fakestoreapi.com/products/' + id)
                .then(response =>  { 
                    console.log(response); //Imprime el curso eliminado
                    this.courses = this.courses.filter(course => course.id !== response.data.id);
                })
                .catch(error =>  {
                    console.log(error);
                });
        },
        cleanInputs() {
            this.course = {
                'title': '',
                'description': '',
                'category': ''
            }
        }
    }
}
</script>

<style lang="">
    
</style>