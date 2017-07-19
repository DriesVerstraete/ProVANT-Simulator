<?xml version="1.0" encoding="UTF-8"?>
<sdf version="1.6">
    <world name="/home/macro/catkin_ws/src/provant_simulator/source/Database/simulation_elements/worlds/templates/empty/empty2.tpl">
        <gravity>0.000000 0.000000 -9.8000</gravity>
        <physics type="ode">
            <max_step_size>0.001000</max_step_size>
            <real_time_factor>0</real_time_factor>
        </physics>
        <plugin name="gazebo_tutorials" filename="libgazebo_ros_world_plugin.so"/>
        <include>
            <uri>model://ground_plane</uri>
            <static>false</static>
        </include>
        <include>
            <uri>model://sun</uri>
            <static>false</static>
        </include>
        <include>
            <uri>model://vant_2.0</uri>
            <name>newmodel</name>
            <static>false</static>
            <pose>0 0 2 0 0 0</pose>
        </include>
        <scene>
            <sky>
                <time>18</time>
                <clouds>
                    <speed>0</speed>
                </clouds>
            </sky>
        </scene>
    </world>
</sdf>
