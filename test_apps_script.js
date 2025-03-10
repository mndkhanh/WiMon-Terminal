/**
  COPYRIGHT - 2025 - THE WIMON TEAM
  Contains references to code written by Rui Santos & Sara Santos - Random Nerd Tutorials
*/

const url = "https://script.google.com/macros/s/AKfycbyOxH6-aAwibfoH5CeH7IBX25vU7WnEe4hXjwi8Q1wyD7t53ewIMZTKjt9xkYJg6Vmi/exec";

async function sendPostRequest(postData) {
  try {
    const response = await fetch(url, {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify(postData),
    });

    const data = await response.json();
    console.log("Response:", data);
  } catch (error) {
    console.error("Error:", error);
  }
}

async function getPatientInfoByID(ID) {
  const fullUrl = `${url}?action=getPatientInfoByID&patientID=${ID}`;
  try {
    const response = await fetch(fullUrl, {
      method: "GET",
    });

    if (!response.ok) {
      throw new Error(`HTTP error! Status: ${response.status}`);
    }

    const data = await response.json();
    console.log("Response:", data);
  } catch (error) {
    console.error("Error:", error);
  }
}

// Gửi post

const postData = {
  action: "append",
  requestTime: Date.now(), // Lấy timestamp dạng số (milliseconds)
  patientID: "P0002",
  spO2: 98,
  HR: 72,
  bodyTemp: 37,
  wimonMAC: "00:1A:2B:3C:4D:5E"
};

sendPostRequest(postData);

getPatientInfoByID("P0003");

