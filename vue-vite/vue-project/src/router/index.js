import { createWebHistory, createRouter } from 'vue-router'

import HomeView from '../views/HomeView.vue'
import AboutView from '../views/AboutView.vue'
import BlogView from '../views/BlogView.vue'

const routes = [
  { path: '/', name: 'home', component: HomeView },
  { path: '/about', name: 'about', component: () => import('../views/AboutView.vue') },
  { path: '/blog', redirect: { name: 'blog'} }, //Ruta de rediceccion, de blog a post
  { path: '/post', name: 'blog', component: BlogView },
  { path: '/blog/:post', name: 'Post', component: () => import('../views/PostView.vue') }, //ruta con params y lazy load, el parametro se guarda en una variable llamada (post)
  { 
    path: '/user/:user/post/:post', 
    name: 'UserPost', 
    component: () => import('../views/UserPostView.vue'), //Ruta con multiples parametros
   }, 
  {
    path: '/user/:userId',
    component: () => import('../views/UsersView.vue'),
    props: true, //Para pasar props a la vista (como el userId)
    children: [ //Rutas anidadas (hijas)
      { path: '', name: 'UserIndex', component: () => import('../views/users/IndexView.vue') }, //user/userId
      { path: 'profile', name: 'UserProfile', component: () => import('../views/users/ProfileView.vue') }, //user/userId/profile
      { path: 'courses', name: 'UserCourses', component: () => import('../views/users/CoursesView.vue') } //user/userId/courses
    ],
  },
  { path: '/:pathMatch(.*)', name: 'NotFound', component: () => import('../views/NotFoundView.vue') },  //ruta para 404
  { path: '/compras/:orderId(\\d+)', name: 'Order', component: () => import('../views/OrderView.vue')}, //El parametro siempre debera ser un numero
  { path: '/compras/:productName', name: 'Product', component: () => import('../views/ProductView.vue')}, 
  { path: '/users/:userId(\\d+)?', name: 'Users', component: () => import('../views/UsersView.vue')}, //Ruta con parametro opcional
]

const router = createRouter({
  history: createWebHistory(),
  routes,
})

export default router