
# Function to enable LinkTimeOptimizations for a given project.
# input: useLinkTimeOptimization, boolean indicating to use LTO or not
# input: project_name, the project name to use

function(link_time_optimization useLinkTimeOptimization project_name)
    # If user indicates LinkTimeOptimizations should be used
    if(${useLinkTimeOptimization})
        # Check if the compiler supports it
        include(CheckIPOSupported)
        check_ipo_supported(RESULT lto_supported OUTPUT error)

        # If it is supported, enable it
        if(lto_supported)
            message(STATUS "IPO / LTO enabled for " ${project_name})
            set_property(TARGET ${project_name} PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
        else()
            message(STATUS "IPO / LTO not supported: <${error}>")
        endif()
    endif()
endfunction()