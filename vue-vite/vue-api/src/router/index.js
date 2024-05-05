import { createRouter, createWebHistory } from 'vue-router'
import HomeView from '../views/HomeView.vue'

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/',
      name: 'home',
      component: HomeView
    },
    {
      path: '/about',
      name: 'about',
      // route level code-splitting
      // this generates a separate chunk (About.[hash].js) for this route
      // which is lazy-loaded when the route is visited.
      component: () => import('../views/AboutView.vue')
    },
    {
      path: '/courses',
      name: 'CoursesList',
      component: () => import('../views/Courses/CoursesList.vue')
    },
    {
      path: '/courses/:id',
      name: 'CourseDetail',
      component: () => import('../views/Courses/CourseDetail.vue')
    },
    {
      path: '/courses/:id/edit',
      name: 'CourseEdit',
      component: () => import('../views/Courses/CourseEdit.vue')
    }
  ]
})

export default router
